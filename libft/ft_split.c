/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:37:04 by pdeson            #+#    #+#             */
/*   Updated: 2023/11/06 15:11:27 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	return (NULL);
}

static int	ft_nbstrs(const char *str, char c)
{
	int	nb;
	int	counted;

	nb = 0;
	counted = 0;
	while (*str)
	{
		if (*str != c && counted == 0)
		{
			nb++;
			counted = 1;
		}
		else if (*str == c)
			counted = 0;
		str++;
	}
	return (nb);
}

char	**ft_gosplit(size_t len, char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= len)
	{
		if (s[i] != c && index < 0 && i < len)
			index = i;
		else if ((s[i] == c || i == len) && index >= 0)
		{
			split[j] = ft_substr(s, index, i - index);
			if (!split[j])
				return (ft_freeall(split, j));
			j++;
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((ft_nbstrs(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_gosplit(ft_strlen(s), split, s, c);
	if (!split)
	{
		free(split);
		return (NULL);
	}
	return (split);
}
