/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_hero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:05:07 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 09:22:05 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mv_r(t_mlx *ml, char pers_char)
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
			{
				ml->map[i][j] = '0';
				ml->map[i][j + 1] = pers_char;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mv_l(t_mlx *ml, char pers_char)
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
			{
				ml->map[i][j] = '0';
				ml->map[i][j - 1] = pers_char;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mv_u(t_mlx *ml, char pers_char)
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
			{
				ml->map[i][j] = '0';
				ml->map[i - 1][j] = pers_char;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mv_d(t_mlx *ml, char pers_char)
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
			{
				ml->map[i][j] = '0';
				ml->map[i + 1][j] = pers_char;
				return ;
			}
			j++;
		}
		i++;
	}
}
