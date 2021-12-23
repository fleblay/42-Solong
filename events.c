/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:02:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/23 13:00:31 by fred             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdlib.h>
#include <stdio.h>

int	treat_press(int keycode, t_mlx *mlx)
{
	if (keycode == 2 && !mlx->hro.mv && !mv_nok(mlx, right, mlx->hro.c))
		mlx->hro.mv = right;
	else if (keycode == 0 && !mlx->hro.mv && !mv_nok(mlx, left, mlx->hro.c))
		mlx->hro.mv = left;
	else if (keycode == 1 && !mlx->hro.mv && !mv_nok(mlx, down, mlx->hro.c))
		mlx->hro.mv = down;
	else if (keycode == 13 && !mlx->hro.mv && !mv_nok(mlx, up, mlx->hro.c))
		mlx->hro.mv = up;
	else if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	treat_click(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf("button keycode >%d<\n", keycode);
	return (0);
}

int	render(t_mlx *ml)
{
	if (ml->timer == 256)
	{
		ml->timer = 0;
		ml->rnd++;
		animate(ml);
	}
	ml->timer++;
	return (0);
}

void	put_background(t_mlx *ml, int (*f)(void *, void *, void *, int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] != '1')
				f(ml->mlx, ml->win, ml->flo, ml->flow * j, ml->floh * i);
			if (ml->map[i][j] == '1')
				f(ml->mlx, ml->win, ml->wal, ml->walw * j, ml->walh * i);
			if (ml->map[i][j] == 'C')
				f(ml->mlx, ml->win, ml->col, ml->colw * j, ml->colh * i);
			if (ml->map[i][j] == 'E')
				f(ml->mlx, ml->win, ml->exi, ml->exiw * j, ml->exih * i);
			if (ml->map[i][j] == 'e')
				f(ml->mlx, ml->win, ml->out, ml->outw * j, ml->outh * i);
			j++;
		}
		i++;
	}
}

void	get_foe_mv(t_mlx *ml)
{
	int	trymv;

	trymv = 0;
	if (ml->foe.wait == 0 && !ml->foe.mv)
	{
		ml->foe.mv = ml->foe.pmv;
		if (!ml->foe.mv)
			ml->foe.mv++;
		while (ml->foe.mv && mv_nok(ml, ml->foe.mv, ml->foe.c))
		{
			if (mv_nok(ml, ml->foe.mv, ml->foe.c) == 'P')
				printf("Colide Hero\n");
			ml->foe.mv = (ml->foe.mv + 1) % 5;
			trymv++;
			if (trymv == 4)
			{
				ml->foe.wait = 20;
				ml->foe.mv = 0;
			}
		}
	ml->foe.pmv = ml->foe.mv;
	}
}
/*
void	get_foe_mv(t_mlx *ml)
{
	int	trymv;

	trymv = 0;
	if (ml->foe.wait == 0 && !ml->foe.mv)
	{
		ml->foe.mv = ml->foe.pmv;
		if (!ml->foe.mv)
			ml->foe.mv++;
		while (ml->foe.mv && !mv_ok(ml, ml->foe.mv, ml->foe.c))
		{
			ml->foe.mv = (ml->foe.mv + 1) % 5;
			if (!ml->foe.mv)
				ml->foe.mv++;
			trymv++;
			if (trymv == 4)
			{
				ml->foe.wait = 20;
				ml->foe.mv = 0;
				break ;
			}
		}
	ml->foe.pmv = ml->foe.mv;
	}
}
*/
