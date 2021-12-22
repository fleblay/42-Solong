/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:02:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 10:54:43 by fle-blay         ###   ########.fr       */
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
			if (ml->map[i][j] == '0' || ml->map[i][j] == 'E'
					|| ml->map[i][j] == 'C' || ml->map[i][j] == 'P')
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

	tab[idle] = &idle_pers;
	tab[right] = &mv_right;
	tab[left] = &mv_left;
	tab[up] = &mv_up;
	tab[down] = &mv_down;
	mlx_clear_window(ml->mlx, ml->win);
	put_background(ml, &mlx_put_image_to_window);
	tab[ml->hro.mv](ml, &mlx_put_image_to_window);
}

int	render(t_mlx *ml)
{
	if (ml->timer == 512)
	{
		ml->timer = 0;
		ml->rnd++;
		animate(ml);
	}
	ml->timer++;
	return (0);
}
