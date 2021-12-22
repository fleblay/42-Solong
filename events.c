/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:02:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 17:38:15 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdlib.h>
#include <stdio.h>

int	treat_press(int keycode, t_mlx *mlx)
{
	if (keycode == 2 && !mlx->hro.mv && mv_ok(mlx, right, mlx->hro.c))
		mlx->hro.mv = right;
	else if (keycode == 0 && !mlx->hro.mv && mv_ok(mlx, left, mlx->hro.c))
		mlx->hro.mv = left;
	else if (keycode == 1 && !mlx->hro.mv && mv_ok(mlx, down, mlx->hro.c))
		mlx->hro.mv = down;
	else if (keycode == 13 && !mlx->hro.mv && mv_ok(mlx, up, mlx->hro.c))
		mlx->hro.mv = up;
	else if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	/*
	int i = 1;
	if (!mlx->foe.mv)
	{
		while (!mv_ok(mlx, i, mlx->foe.c))
			i++;
	}
	mlx->foe.mv = i;
	*/
	return (0);
}

int	treat_click(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf("button keycode >%d<\n", keycode);
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
				f(ml->mlx, ml->win, ml->out, ml->outw * j, ml->outh * i); j++;
		}
		i++;
	}
}

void	animate(t_mlx *ml)
{
	void	(*tab[5])(t_mlx *m, int (*f)(void *, void *, void *, int, int));
	void	(*tab2[5])(t_mlx *m, int (*f)(void *, void *, void *, int, int));

	tab[idle] = &idle_pers;
	tab[right] = &mv_right;
	tab[left] = &mv_left;
	tab[up] = &mv_up;
	tab[down] = &mv_down;

	tab2[idle] = &idle_persfoe;
	tab2[right] = &mv_rightfoe;
	tab2[left] = &mv_leftfoe;
	tab2[up] = &mv_upfoe;
	tab2[down] = &mv_downfoe;

	mlx_clear_window(ml->mlx, ml->win);
	put_background(ml, &mlx_put_image_to_window);
	tab[ml->hro.mv](ml, &mlx_put_image_to_window);

	static int prev = 1;

	//printf("BEFORE prev : %d foe.mv : %d foe.bsy : %d\n", prev, ml->foe.mv, ml->foe.bsy);
	if (!ml->foe.mv)
	{
		ml->foe.mv = prev;
		//if (!ml->foe.mv)
		//	ml->foe.mv++;
		while (!mv_ok(ml, ml->foe.mv, ml->foe.c))
		{
			ml->foe.mv++;
			ml->foe.mv = ml->foe.mv % 5;
			if (!ml->foe.mv)
				ml->foe.mv++;
		}
	prev = ml->foe.mv;
	}
	//printf("AFTER prev : %d foe.mv : %d foe.bsy : %d\n",prev, ml->foe.mv, ml->foe.bsy);

	tab2[ml->foe.mv](ml, &mlx_put_image_to_window);
	if (!isany(ml, 'C'))
		replace1(ml, 'E', 'e');
}

int	render(t_mlx *ml)
{
	if (ml->timer == 400)
	{
		ml->timer = 0;
		ml->rnd++;
		animate(ml);
	}
	ml->timer++;
	return (0);
}
