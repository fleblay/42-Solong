/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:09:55 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 15:22:02 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdio.h>

void	idle_persfoe(t_mlx *ml, int (*f)(void *, void *, void *, int, int))
{
	if (ml->foe.mv == 0 && !ml->foe.rev)
		f(ml->mlx, ml->win, ml->foe.idl[ml->rnd % 6], ml->foe.x, ml->foe.y);
	if (ml->foe.mv == 0 && ml->foe.rev)
		f(ml->mlx, ml->win, ml->foe.ridl[ml->rnd % 6], ml->foe.x, ml->foe.y);
}

void	mv_rightfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->foe.bsy == 0)
		ml->foe.x += 4;
	ml->foe.x += 10;
	fx(ml->mlx, ml->win, ml->foe.run[ml->foe.bsy], ml->foe.x, ml->foe.y);
	ml->foe.bsy++;
	if (ml->foe.bsy == 6)
	{
		ml->foe.mv = 0;
		ml->foe.bsy = 0;
		ml->foe.rev = 0;
		mv_r(ml, ml->foe.c);
	}
}

void	mv_leftfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->foe.bsy == 0)
		ml->foe.x -= 4;
	ml->foe.x -= 10;
	fx(ml->mlx, ml->win, ml->foe.rrun[ml->foe.bsy], ml->foe.x, ml->foe.y);
	ml->foe.bsy++;
	if (ml->foe.bsy == 6)
	{
		ml->foe.mv = 0;
		ml->foe.bsy = 0;
		ml->foe.rev = 1;
		mv_l(ml, ml->foe.c);
	}
}

void	mv_upfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->foe.bsy == 0)
		ml->foe.y -= 4;
	ml->foe.y -= 10;
	if (ml->foe.rev)
		fx(ml->mlx, ml->win, ml->foe.rrun[ml->foe.bsy], ml->foe.x, ml->foe.y);
	else
		fx(ml->mlx, ml->win, ml->foe.run[ml->foe.bsy], ml->foe.x, ml->foe.y);
	ml->foe.bsy++;
	if (ml->foe.bsy == 6)
	{
		ml->foe.mv = 0;
		ml->foe.bsy = 0;
		mv_u(ml, ml->foe.c);
	}
}

void	mv_downfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int))
{
	if (ml->foe.bsy == 0)
		ml->foe.y += 4;
	ml->foe.y += 10;
	if (ml->foe.rev)
		fx(ml->mlx, ml->win, ml->foe.rrun[ml->foe.bsy], ml->foe.x, ml->foe.y);
	else
		fx(ml->mlx, ml->win, ml->foe.run[ml->foe.bsy], ml->foe.x, ml->foe.y);
	ml->foe.bsy++;
	if (ml->foe.bsy == 6)
	{
		ml->foe.mv = 0;
		ml->foe.bsy = 0;
		mv_d(ml, ml->foe.c);
	}
}
