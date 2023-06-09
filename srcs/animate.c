/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:51:19 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/29 10:27:03 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	idle_pers(t_mlx *ml, int (*f)(void *, void *, void *, int, int))
{
	if (ml->hro.mv == 0 && !ml->hro.rev)
		f(ml->mlx, ml->win, ml->hro.idl[ml->rnd % 6], ml->hro.x, ml->hro.y);
	if (ml->hro.mv == 0 && ml->hro.rev)
		f(ml->mlx, ml->win, ml->hro.ridl[ml->rnd % 6], ml->hro.x, ml->hro.y);
}

void	mv_right(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->hro.bsy == 0)
	{
		mv_r(ml, ml->hro.c);
		ml->hro.x += 4;
	}
	ml->hro.x += 10;
	fx(ml->mlx, ml->win, ml->hro.run[ml->hro.bsy], ml->hro.x, ml->hro.y);
	ml->hro.bsy++;
	if (ml->hro.bsy == 6)
	{
		ml->hro.mv = 0;
		ml->hro.bsy = 0;
		ml->hro.rev = 0;
	}
}

void	mv_left(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->hro.bsy == 0)
	{
		mv_l(ml, ml->hro.c);
		ml->hro.x -= 4;
	}
	ml->hro.x -= 10;
	fx(ml->mlx, ml->win, ml->hro.rrun[ml->hro.bsy], ml->hro.x, ml->hro.y);
	ml->hro.bsy++;
	if (ml->hro.bsy == 6)
	{
		ml->hro.mv = 0;
		ml->hro.bsy = 0;
		ml->hro.rev = 1;
	}
}

void	mv_up(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->hro.bsy == 0)
	{
		mv_u(ml, ml->hro.c);
		ml->hro.y -= 4;
	}
	ml->hro.y -= 10;
	if (ml->hro.rev)
		fx(ml->mlx, ml->win, ml->hro.rrun[ml->hro.bsy], ml->hro.x, ml->hro.y);
	else
		fx(ml->mlx, ml->win, ml->hro.run[ml->hro.bsy], ml->hro.x, ml->hro.y);
	ml->hro.bsy++;
	if (ml->hro.bsy == 6)
	{
		ml->hro.mv = 0;
		ml->hro.bsy = 0;
	}
}

void	mv_down(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->hro.bsy == 0)
	{
		mv_d(ml, ml->hro.c);
		ml->hro.y += 4;
	}
	ml->hro.y += 10;
	if (ml->hro.rev)
		fx(ml->mlx, ml->win, ml->hro.rrun[ml->hro.bsy], ml->hro.x, ml->hro.y);
	else
		fx(ml->mlx, ml->win, ml->hro.run[ml->hro.bsy], ml->hro.x, ml->hro.y);
	ml->hro.bsy++;
	if (ml->hro.bsy == 6)
	{
		ml->hro.mv = 0;
		ml->hro.bsy = 0;
	}
}
