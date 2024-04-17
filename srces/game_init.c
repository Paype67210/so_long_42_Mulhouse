/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:16:15 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 10:24:21 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectables(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 64, height * 64);
	game->collectables++;
}

void	adding_in_graphics(t_complete *game, int height)
{
	int	width;

	game->collectables = 0;
	while (height < game->highmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->barrier, width * 64, height * 64);
			if (game->map[height][width] == 'C')
				place_collectables(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->exit, width * 64, height * 64);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, width * 64, height * 64);
			width++;
		}
		height++;
	}
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == ESC)
		ft_free_exit(game);
	if (command == 'w')
		works = ft_hint_w(game);
	if (command == 's')
		works = ft_hint_s(game);
	if (command == 'd')
		works = ft_hint_d(game);
	if (command == 'a')
		works = ft_hint_a(game);
	if (works)
		adding_in_graphics(game, 0);
	return (1);
}
