/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:00:55 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/05 08:37:57 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_complete
{
	int		fd;
	int		highmap;
	int		widthmap;
	int		playercount;
	int		exitcount;
	int		collectcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

# define ESC 65307

char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str, const char *s2, size_t n);
void	*ft_memset(void *mtr, int c, size_t n);
int		ft_mapverif(t_complete *game, char *map);
void	ft_free_exit(t_complete *game);
void	ft_verifgrid(t_complete *game);
void	ft_verifwalls(t_complete *game);
void	ft_verifroute(t_complete *game);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(char *s);
char	**ft_map_dup(char **srce);
int		ft_count_ec(char **map);
void	ft_check_argvs(int argc, char **argv);

/*----- GRAPH PART -----*/
void	ft_init_images(t_complete *game, int value);
void	ft_init_imagesbis(t_complete *game, int value);
int		ft_close(int keycode, t_complete *game);
int		ft_close_window(t_complete *game);
int		controls_working(int command, t_complete *game);
int		ft_hint_d(t_complete *game);
int		ft_hint_a(t_complete *game);
int		ft_hint_w(t_complete *game);
int		ft_hint_s(t_complete *game);
void	adding_in_graphics(t_complete *game, int height);

#endif
