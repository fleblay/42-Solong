/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:00:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/27 10:46:42 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stddef.h>

void	init_pers(t_pers *pers, char pers_char)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		pers->idl[i] = NULL;
		pers->ridl[i] = NULL;
		pers->run[i] = NULL;
		pers->rrun[i] = NULL;
	}
	pers->c = pers_char;
	pers->x = 0;
	pers->y = 0;
	pers->mv = 0;
	pers->rev = 0;
	pers->bsy = 0;
	pers->pmv = right;
	pers->wait = 0;
	pers->steps = 0;
	pers->exist = 0;
}

void	init_mlx_struct(t_mlx *ml)
{
	int	i;

	i = -1;
	ml->timer = 0;
	ml->rnd = 0;
	ml->gameover = 0;
	ml->map = NULL;
	ml->flo = NULL;
	ml->wal = NULL;
	ml->exi = NULL;
	ml->col = NULL;
	while (++i < 15)
		ml->out2[i] = NULL;
	ml->anim = -1;
	ml->maph = 0;
	ml->mapw = 0;
}

void	set_mlx_struct(t_mlx *ml, char *name, char *file)
{
	init_mlx_struct(ml);
	init_pers(&(ml->hro), 'P');
	init_pers(&(ml->foe), 'F');
	ml->mlx = mlx_init();
	load_hero_img(ml, &custom_load_xpm);
	load_foe_img(ml, &custom_load_xpm);
	load_map_img(ml, &custom_load_xpm);
	getmap(file, ml);
	ml->win = mlx_new_window(ml->mlx, ml->mapw * ml->flow,
			ml->maph * ml->floh, name);
}
