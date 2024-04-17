/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:02:30 by pdeson            #+#    #+#             */
/*   Updated: 2024/04/17 10:24:25 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_check_argvs(int argc, char **argv)
{
	char	*str;
	int		len;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Too many ARGS!\n");
		exit (EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	str = argv[1] + (len - 4);
	if (ft_strncmp(str, ".ber", 4) != 0)
	{
		ft_printf("ARG is not a file with .ber extension!\n");
		exit (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("map!");
		exit (EXIT_FAILURE);
	}
	close(fd);
}
