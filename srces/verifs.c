/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:05 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 10:24:33 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static size_t	ft_width(const char *str)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	return (count);
}

static int	add_line(t_complete *game, char *line)
{
	char	**buffer;
	int		i;

	if (!line || !game)
		return (-1);
	i = 0;
	buffer = (char **)malloc(sizeof(char *) * (game->highmap + 2));
	if (!buffer)
	{
		if (game->map)
			ft_free_exit(game);
		exit (EXIT_FAILURE);
	}
	while (i < game->highmap)
	{
		buffer[i] = game->map[i];
		i++;
	}
	buffer[i++] = line;
	buffer[i] = NULL;
	if (game->map)
		free(game->map);
	game->map = buffer;
	game->highmap++;
	return (1);
}

int	ft_mapverif(t_complete *game, char *map)
{
	char	*readmap;

	if (!game || !map)
		return (-1);
	game->fd = open(map, O_RDONLY);
	if (game->fd < 0)
		ft_free_exit(game);
	readmap = get_next_line(game->fd);
	while (readmap)
	{
		if (!add_line(game, readmap))
		{
			free(readmap);
			break ;
		}
		readmap = get_next_line(game->fd);
	}
	close (game->fd);
	if (!game->map)
	{
		ft_free_exit(game);
	}
	if (game->map)
		game->widthmap = ft_width(game->map[0]);
	return (1);
}

int	ft_count_ec(char **map)
{
	int		height;
	int		width;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == 'C' ||
				map[height][width] == 'E')
				return (0);
			width++;
		}
		height++;
	}
	return (1);
}

char	**ft_map_dup(char **srce)
{
	int		i;
	char	**buffer;

	i = 0;
	if (!srce)
		return (NULL);
	while (srce[i])
		i++;
	buffer = (char **)malloc(sizeof(char *) * (i + 1));
	if (!buffer)
		exit (EXIT_FAILURE);
	i = 0;
	while (srce[i])
	{
		buffer[i] = ft_strdup(srce[i]);
		if (!buffer[i++])
		{
			while (i > 0)
				free(buffer[--i]);
			free(buffer);
			exit (EXIT_FAILURE);
		}
	}
	buffer[i] = NULL;
	return (buffer);
}
