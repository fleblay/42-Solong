/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:02:05 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 09:56:43 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	r_is(t_mlx *ml, char pers_char)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == pers_char)
				return (ml->map[i][j + 1]);
			j++;
		}
		i++;
	}
	return (0);
}

char	l_is(t_mlx *ml, char pers_char)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == pers_char)
				return (ml->map[i][j - 1]);
			j++;
		}
		i++;
	}
	return (0);
}

char	u_is(t_mlx *ml, char pers_char)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == pers_char)
				return (ml->map[i - 1][j]);
			j++;
		}
		i++;
	}
	return (0);
}

char	d_is(t_mlx *ml, char pers_char)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == pers_char)
				return (ml->map[i + 1][j]);
			j++;
		}
		i++;
	}
	return (0);
}
