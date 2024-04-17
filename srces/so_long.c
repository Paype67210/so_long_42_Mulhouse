/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:51:15 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 10:24:28 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_fill_grid(t_complete *game, char **buffer, int x, int y)
{
	if (x < 0 || x >= game->widthmap || y >= game->highmap || \
		y < 0 || buffer[y][x] == '1')
		return ;
	buffer[y][x] = '1';
	ft_fill_grid(game, buffer, x - 1, y);
	ft_fill_grid(game, buffer, x + 1, y);
	ft_fill_grid(game, buffer, x, y - 1);
	ft_fill_grid(game, buffer, x, y + 1);
}

void	ft_verifroute(t_complete *game)
{
	char	**buffer;
	int		i;

	buffer = ft_map_dup(game->map);
	ft_fill_grid(game, buffer, game->x_axis, game->y_axis);
	if (!ft_count_ec(buffer))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("No issues possible\n");
		i = 0;
		while (buffer[i])
			free(buffer[i++]);
		free(buffer);
		ft_free_exit(game);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (buffer[i])
		free(buffer[i++]);
	free(buffer);
}

void	ft_init_images(t_complete *game, int value)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"images/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"images/wall.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"images/object.xpm", &i, &j);
	if (game->collectables == 0)
		game->exit = mlx_xpm_file_to_image(game->mlxpointer,
				"images/exit.xpm", &i, &j);
	else
		game->exit = mlx_xpm_file_to_image(game->mlxpointer,
				"images/exitNO.xpm", &i, &j);
	ft_init_imagesbis(game, value);
}

void	ft_init_imagesbis(t_complete *game, int value)
{
	int	i;
	int	j;

	if (value == 0 || value == 100)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"images/player.xpm", &i, &j);
	else if (value == 97)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"images/playerA.xpm", &i, &j);
	else if (value == 119)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"images/playerW.xpm", &i, &j);
	else if (value == 115)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"images/playerS.xpm", &i, &j);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	ft_check_argvs(argc, argv);
	ft_memset(&game, 0, sizeof(t_complete));
	ft_mapverif(&game, argv[1]);
	ft_verifwalls(&game);
	ft_verifgrid(&game);
	ft_verifroute(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 64),
			(game.highmap * 64), "SoLong");
	ft_init_images(&game, 0);
	adding_in_graphics(&game, 0);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 2, 1L << 0, ft_close, &game);
	mlx_hook(game.winpointer, 17, 1L << 17, ft_close_window, &game);
	mlx_loop(game.mlxpointer);
	exit(EXIT_SUCCESS);
}
