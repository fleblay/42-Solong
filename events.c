/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:02:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/21 12:07:53 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdlib.h>
#include <stdio.h>

int	treat_press(int keycode, t_mlx *mlx)
{
	if (keycode == 2 && !mlx->hro.mv)
		mlx->hro.mv = right;
	if (keycode == 0 && !mlx->hro.mv)
		mlx->hro.mv = left;
	if (keycode == 1 && !mlx->hro.mv)
		mlx->hro.mv = down;
	if (keycode == 13 && !mlx->hro.mv)
		mlx->hro.mv = up;
	if (keycode == 53)
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

void	animate(t_mlx *ml)
{
	void	(*tab[5])(t_mlx *m, int (*f)(void *, void *, void *, int, int));

	tab[idle] = &idle_pers;
	tab[right] = &mv_right;
	tab[left] = &mv_left;
	tab[up] = &mv_up;
	tab[down] = &mv_down;
	mlx_clear_window(ml->mlx, ml->win);
	tab[ml->hro.mv](ml, &mlx_put_image_to_window);
}

int	render(t_mlx *ml)
{
	if (ml->timer == 1024)
	{
		ml->timer = 0;
		ml->rnd++;
		animate(ml);
	}
	ml->timer++;
	return (0);
}
