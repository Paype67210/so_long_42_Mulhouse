/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:44:37 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 10:24:14 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_free_images(t_complete *game)
{
	if (!game)
		return ;
	mlx_destroy_image(game->mlxpointer, game->barrier);
	mlx_destroy_image(game->mlxpointer, game->floor);
	mlx_destroy_image(game->mlxpointer, game->collectable);
	mlx_destroy_image(game->mlxpointer, game->exit);
	mlx_destroy_image(game->mlxpointer, game->player);
}

int	ft_close(int keycode, t_complete *game)
{
	if (!game)
		return (-1);
	if (keycode == ESC)
	{
		ft_free_exit(game);
		ft_printf("You gave up!\n");
		exit (EXIT_SUCCESS);
	}
	return (1);
}

int	ft_close_window(t_complete *game)
{
	if (!game)
		return (-1);
	ft_free_exit(game);
	ft_printf("You gave up!\n");
	exit (EXIT_SUCCESS);
}

void	ft_free_exit(t_complete *game)
{
	int	line;

	if (!game)
		return ;
	if (game->winpointer)
	{
		ft_free_images(game);
		mlx_destroy_window(game->mlxpointer, game->winpointer);
		mlx_destroy_display(game->mlxpointer);
	}
	line = 0;
	if (game->mlxpointer)
		free(game->mlxpointer);
	if (game->map)
	{
		while (game->map[line])
			free(game->map[line++]);
		free(game->map);
	}
}
