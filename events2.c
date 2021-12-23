/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fred <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:00:18 by fred              #+#    #+#             */
/*   Updated: 2021/12/23 12:00:23 by fred             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include "libft.h"

void	load_fx_mv(void (*tab1[])(), void (*tab2[])())
{
	tab1[idle] = &idle_pers;
	tab1[right] = &mv_right;
	tab1[left] = &mv_left;
	tab1[up] = &mv_up;
	tab1[down] = &mv_down;
	tab2[idle] = &idle_persfoe;
	tab2[right] = &mv_rightfoe;
	tab2[left] = &mv_leftfoe;
	tab2[up] = &mv_upfoe;
	tab2[down] = &mv_downfoe;
}

void	animate(t_mlx *ml)
{
	void	(*hro_mv[5])(t_mlx *m, int (*f)(void *, void *, void *, int, int));
	void	(*foe_mv[5])(t_mlx *m, int (*f)(void *, void *, void *, int, int));

	load_fx_mv(hro_mv, foe_mv);
	mlx_clear_window(ml->mlx, ml->win);
	put_background(ml, &mlx_put_image_to_window);
	mlx_string_put(ml->mlx, ml->win, 0, 12, 0x00FF0000, ft_itoa(ml->hro.steps));
	hro_mv[ml->hro.mv](ml, &mlx_put_image_to_window);
	get_foe_mv(ml);
	foe_mv[ml->foe.mv](ml, &mlx_put_image_to_window);
	if (!isany(ml, 'C'))
		replace1(ml, 'E', 'e');
	if (ml->foe.wait > 0)
		ml->foe.wait--;
}

	/*printf("BEFORE waiting : %d ml->rnd : %d prev : %d foe.mv : %d foe.bsy/
	: %d\n", ml->foe.wait,  ml->rnd, ml->foe.pmv, ml->foe.mv, ml->foe.bsy);*/
