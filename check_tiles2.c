/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tiles2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:11:43 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 10:54:55 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stddef.h>

int	mv_ok(t_mlx *ml, int move, char pers_char)
{
	char	(*tab[5])(t_mlx *, char);
	int		tile;

	tab[0] = NULL;
	tab[1] = &r_is; 
	tab[2] = &l_is; 
	tab[3] = &u_is; 
	tab[4] = &d_is; 
	tile = tab[move](ml, pers_char);
	if (tile == '0' || tile == 'C')
		return (1);
	return (0);
}

int	isany(t_mlx *ml, char pers_char)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	replace1(t_mlx *ml, char old, char nw)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == old)
			{
				ml->map[i][j] = nw;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
