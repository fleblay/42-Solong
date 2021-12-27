/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:34:54 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/27 10:16:54 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stddef.h>

void	*custom_load_xpm(t_mlx *ml, char *path, int *w, int *h)
{
	void	*ret;

	ret = mlx_xpm_file_to_image(ml->mlx, path, w, h);
	if (!ret)
		custom_exit(ml);
	return (ret);
}

void	load_hero_img(t_mlx *ml, void *(*f)(t_mlx *, char *, int *, int *))
{
	ml->hro.idl[0] = f(ml, "./img/k_i0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[1] = f(ml, "./img/k_i1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[2] = f(ml, "./img/k_i2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[3] = f(ml, "./img/k_i3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[4] = f(ml, "./img/k_i4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.idl[5] = f(ml, "./img/k_i5.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[0] = f(ml, "./img/k_ri0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[1] = f(ml, "./img/k_ri1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[2] = f(ml, "./img/k_ri2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[3] = f(ml, "./img/k_ri3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[4] = f(ml, "./img/k_ri4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.ridl[5] = f(ml, "./img/k_ri5.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[0] = f(ml, "./img/k_r0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[1] = f(ml, "./img/k_r1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[2] = f(ml, "./img/k_r2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[3] = f(ml, "./img/k_r3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[4] = f(ml, "./img/k_r4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.run[5] = f(ml, "./img/k_r5.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[0] = f(ml, "./img/k_rr0.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[1] = f(ml, "./img/k_rr1.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[2] = f(ml, "./img/k_rr2.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[3] = f(ml, "./img/k_rr3.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[4] = f(ml, "./img/k_rr4.xpm", &(ml->hro.w), &(ml->hro.h));
	ml->hro.rrun[5] = f(ml, "./img/k_rr5.xpm", &(ml->hro.w), &(ml->hro.h));
}

void	load_foe_img(t_mlx *ml, void *(*f)(t_mlx *, char *, int *, int *))
{
	ml->foe.idl[0] = f(ml, "./img/g_i0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[1] = f(ml, "./img/g_i1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[2] = f(ml, "./img/g_i2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[3] = f(ml, "./img/g_i3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[4] = f(ml, "./img/g_i4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.idl[5] = f(ml, "./img/g_i5.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[0] = f(ml, "./img/g_ri0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[1] = f(ml, "./img/g_ri1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[2] = f(ml, "./img/g_ri2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[3] = f(ml, "./img/g_ri3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[4] = f(ml, "./img/g_ri4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.ridl[5] = f(ml, "./img/g_ri5.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[0] = f(ml, "./img/g_r0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[1] = f(ml, "./img/g_r1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[2] = f(ml, "./img/g_r2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[3] = f(ml, "./img/g_r3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[4] = f(ml, "./img/g_r4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.run[5] = f(ml, "./img/g_r5.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[0] = f(ml, "./img/g_rr0.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[1] = f(ml, "./img/g_rr1.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[2] = f(ml, "./img/g_rr2.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[3] = f(ml, "./img/g_rr3.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[4] = f(ml, "./img/g_rr4.xpm", &(ml->foe.w), &(ml->foe.h));
	ml->foe.rrun[5] = f(ml, "./img/g_rr5.xpm", &(ml->foe.w), &(ml->foe.h));
}

void	load_map_img(t_mlx *ml, void *(*f)(t_mlx *, char *, int *, int *))
{
	ml->flo = f(ml, "./img/flo.xpm", &(ml->flow), &(ml->floh));
	ml->wal = f(ml, "./img/wal.xpm", &(ml->walw), &(ml->walh));
	ml->exi = f(ml, "./img/exi.xpm", &(ml->exiw), &(ml->exih));
	ml->col = f(ml, "./img/col.xpm", &(ml->colw), &(ml->colh));
	ml->out2[0] = f(ml, "./img/out2_0.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[1] = f(ml, "./img/out2_1.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[2] = f(ml, "./img/out2_2.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[3] = f(ml, "./img/out2_3.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[4] = f(ml, "./img/out2_4.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[5] = f(ml, "./img/out2_5.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[6] = f(ml, "./img/out2_6.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[7] = f(ml, "./img/out2_7.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[8] = f(ml, "./img/out2_8.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[9] = f(ml, "./img/out2_9.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[10] = f(ml, "./img/out2_10.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[11] = f(ml, "./img/out2_11.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[12] = f(ml, "./img/out2_12.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[13] = f(ml, "./img/out2_13.xpm", &(ml->out2w), &(ml->out2h));
	ml->out2[14] = f(ml, "./img/out.xpm", &(ml->out2w), &(ml->out2h));
}
