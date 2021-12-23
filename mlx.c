/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:00:50 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/23 18:08:39 by fle-blay         ###   ########.fr       */
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
}

void	init_mlx_struct(t_mlx *ml, char *name, char *file)
{
	int	i;

	i = -1;
	ml->timer = 0;
	ml->rnd = 0;
	ml->gameover = 0;
	init_pers(&(ml->hro), 'P');
	init_pers(&(ml->foe), 'F');
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
	ml->mlx = mlx_init();
	load_hero_img(ml, &mlx_xpm_file_to_image);
	load_foe_img(ml, &mlx_xpm_file_to_image);
	load_map_img(ml, &mlx_xpm_file_to_image);
	getmap(file, ml);
	ml->win = mlx_new_window(ml->mlx, ml->mapw * ml->flow,
			ml->maph * ml->floh, name);
}

void	load_hero_img(t_mlx *ml, void *(*f)(void *, char *, int *, int *))
{
	ml->hro.idl[0] = f(ml->mlx, "./img/k_i0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[1] = f(ml->mlx, "./img/k_i1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[2] = f(ml->mlx, "./img/k_i2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[3] = f(ml->mlx, "./img/k_i3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[4] = f(ml->mlx, "./img/k_i4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[5] = f(ml->mlx, "./img/k_i5.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[0] = f(ml->mlx, "./img/k_ri0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[1] = f(ml->mlx, "./img/k_ri1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[2] = f(ml->mlx, "./img/k_ri2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[3] = f(ml->mlx, "./img/k_ri3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[4] = f(ml->mlx, "./img/k_ri4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[5] = f(ml->mlx, "./img/k_ri5.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[0] = f(ml->mlx, "./img/k_r0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[1] = f(ml->mlx, "./img/k_r1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[2] = f(ml->mlx, "./img/k_r2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[3] = f(ml->mlx, "./img/k_r3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[4] = f(ml->mlx, "./img/k_r4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[5] = f(ml->mlx, "./img/k_r5.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[0] = f(ml->mlx, "./img/k_rr0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[1] = f(ml->mlx, "./img/k_rr1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[2] = f(ml->mlx, "./img/k_rr2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[3] = f(ml->mlx, "./img/k_rr3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[4] = f(ml->mlx, "./img/k_rr4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[5] = f(ml->mlx, "./img/k_rr5.xpm", &(ml->hro.w), &(ml->hro.h));
}

void	load_foe_img(t_mlx *ml, void *(*f)(void *, char *, int *, int *))
{
	ml->foe.idl[0] = f(ml->mlx, "./img/g_i0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[1] = f(ml->mlx, "./img/g_i1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[2] = f(ml->mlx, "./img/g_i2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[3] = f(ml->mlx, "./img/g_i3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[4] = f(ml->mlx, "./img/g_i4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[5] = f(ml->mlx, "./img/g_i5.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[0] = f(ml->mlx, "./img/g_ri0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[1] = f(ml->mlx, "./img/g_ri1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[2] = f(ml->mlx, "./img/g_ri2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[3] = f(ml->mlx, "./img/g_ri3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[4] = f(ml->mlx, "./img/g_ri4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[5] = f(ml->mlx, "./img/g_ri5.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[0] = f(ml->mlx, "./img/g_r0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[1] = f(ml->mlx, "./img/g_r1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[2] = f(ml->mlx, "./img/g_r2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[3] = f(ml->mlx, "./img/g_r3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[4] = f(ml->mlx, "./img/g_r4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[5] = f(ml->mlx, "./img/g_r5.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[0] = f(ml->mlx, "./img/g_rr0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[1] = f(ml->mlx, "./img/g_rr1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[2] = f(ml->mlx, "./img/g_rr2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[3] = f(ml->mlx, "./img/g_rr3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[4] = f(ml->mlx, "./img/g_rr4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[5] = f(ml->mlx, "./img/g_rr5.xpm", &(ml->foe.w), &(ml->foe.h));
}

void	load_map_img(t_mlx *ml, void *(*f)(void *, char *, int *, int *))
{
	ml->flo = f(ml->mlx, "./img/flo.xpm", &(ml->flow), &(ml->floh));
	ml->wal = f(ml->mlx, "./img/wal.xpm", &(ml->walw), &(ml->walh));
	ml->exi = f(ml->mlx, "./img/exi.xpm", &(ml->exiw), &(ml->exih));
	ml->col = f(ml->mlx, "./img/col.xpm", &(ml->colw), &(ml->colh));
	ml->out2[0] = f(ml->mlx, "./img/out2_0.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[1] = f(ml->mlx, "./img/out2_1.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[2] = f(ml->mlx, "./img/out2_2.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[3] = f(ml->mlx, "./img/out2_3.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[4] = f(ml->mlx, "./img/out2_4.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[5] = f(ml->mlx, "./img/out2_5.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[6] = f(ml->mlx, "./img/out2_6.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[7] = f(ml->mlx, "./img/out2_7.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[8] = f(ml->mlx, "./img/out2_8.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[9] = f(ml->mlx, "./img/out2_9.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[10] = f(ml->mlx, "./img/out2_10.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[11] = f(ml->mlx, "./img/out2_11.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[12] = f(ml->mlx, "./img/out2_12.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[13] = f(ml->mlx, "./img/out2_13.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[14] = f(ml->mlx, "./img/out.xpm", &(ml->out2w), &(ml->out2h));
}
