/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:17:42 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 10:24:07 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	horizontalwall(t_complete *game)
{
	int	i;

	i = game->widthmap;
	while (--i >= 0)
	{
		if (game->map[0][i] != '1' || game->map[game->highmap - 1][i] != '1')
			return (0);
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	j;

	j = game->highmap;
	while (--j >= 0)
	{
		if (game->map[j][0] != '1' || game->map[j][game->widthmap - 1] != '1')
			return (0);
	}
	return (1);
}

void	ft_verifwalls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf("\nThe map is missing walls around\n");
		ft_free_exit(game);
		exit(EXIT_FAILURE);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError [%c]\n", game->map[height][width]);
		ft_free_exit(game);
		exit (EXIT_FAILURE);
	}
	if (game->map[height][width] == 'C')
		game->collectcount++;
	if (game->map[height][width] == 'P')
	{
		game->playercount++;
		game->x_axis = width;
		game->y_axis = height;
	}
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	ft_verifgrid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->highmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->collectcount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("either player, exit or collectable issue\n");
		ft_free_exit(game);
		exit (EXIT_FAILURE);
	}
}
