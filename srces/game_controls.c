/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:41:11 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 10:24:18 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nYou Have Won, Congrats!\n");
		ft_free_exit(game);
		exit (EXIT_SUCCESS);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

int	ft_hint_w(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j--;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j + 1][i] = '0';
	printf("Steps : %i\tItems left: %i\n", game->counter, game->collectables);
	return (1);
}

int	ft_hint_s(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j++;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j - 1][i] = '0';
	printf("Steps : %i\tItems left: %i\n", game->counter, game->collectables);
	return (1);
}

int	ft_hint_d(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i++;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i - 1] = '0';
	printf("Steps : %i\tItems left: %i\n", game->counter, game->collectables);
	return (1);
}

int	ft_hint_a(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i--;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i + 1] = '0';
	printf("Steps : %i\tItems left: %i\n", game->counter, game->collectables);
	return (1);
}
