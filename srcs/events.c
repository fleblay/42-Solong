/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:02:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/29 10:27:03 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int	treat_press(int keycode, t_mlx *ml)
{
	if (keycode == KEY_R && !ml->hro.mv && !mv_nok(ml, right, ml->hro.c))
		ml->hro.mv = right;
	else if (keycode == KEY_L && !ml->hro.mv && !mv_nok(ml, left, ml->hro.c))
		ml->hro.mv = left;
	else if (keycode == KEY_D && !ml->hro.mv && !mv_nok(ml, down, ml->hro.c))
		ml->hro.mv = down;
	else if (keycode == KEY_U && !ml->hro.mv && !mv_nok(ml, up, ml->hro.c))
		ml->hro.mv = up;
	else if (keycode == KEY_ESC)
		custom_exit(ml);
	return (0);
}

int	render(t_mlx *ml)
{
	if (ml->timer == SPEED)
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

	i = -1;
	while (++i < ml->maph)
	{
		j = -1;
		while (++j < ml->mapw)
		{
			if (ml->map[i][j] != '1')
				f(ml->mlx, ml->win, ml->flo, ml->flow * j, ml->floh * i);
			if (ml->map[i][j] == '1')
				f(ml->mlx, ml->win, ml->wal, ml->walw * j, ml->walh * i);
			if (ml->map[i][j] == 'C')
				f(ml->mlx, ml->win, ml->col, ml->colw * j, ml->colh * i);
			if (ml->map[i][j] == 'E')
				f(ml->mlx, ml->win, ml->exi, ml->exiw * j, ml->exih * i);
			if (ml->map[i][j] == 'e' && ml->anim >= 0)
				f(ml->mlx, ml->win, ml->out2[ml->anim], ml->out2w * j, \
				ml->out2h * i);
		}
	}
	if (ml->anim >= 0 && ml->anim < 14)
		ml->anim++;
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
				ml->gameover = 1;
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
old version for minilibx_opengl
int	treat_press(int keycode, t_mlx *ml)
{
	if (keycode == 2 && !ml->hro.mv && !mv_nok(ml, right, ml->hro.c))
		ml->hro.mv = right;
	else if (keycode == 0 && !ml->hro.mv && !mv_nok(ml, left, ml->hro.c))
		ml->hro.mv = left;
	else if (keycode == 1 && !ml->hro.mv && !mv_nok(ml, down, ml->hro.c))
		ml->hro.mv = down;
	else if (keycode == 13 && !ml->hro.mv && !mv_nok(ml, up, ml->hro.c))
		ml->hro.mv = up;
	else if (keycode == 53)
		custom_exit(ml);
	printf("keycode : %d\n", keycode);
	return (0);
}
*/
