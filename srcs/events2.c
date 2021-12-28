/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fred <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:00:18 by fred              #+#    #+#             */
/*   Updated: 2021/12/28 15:07:14 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include "libft.h"
#include <stdio.h>

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

int	put_score(t_mlx *ml)
{
	char		*score;
	static int	current_step = 0;

	score = ft_itoa(ml->hro.steps);
	if (!score)
		return (0);
	(BONUS) && mlx_string_put(ml->mlx, ml->win, 0, 12, 0x00FF0000, score);
	if (current_step != ml->hro.steps)
	{
		(!BONUS) && printf("Score : %s\n", score);
		current_step = ml->hro.steps;
	}
	free(score);
	if (ml->gameover)
	{
		ml->hro.mv = idle;
		ml->foe.mv = idle;
		if (ml->gameover == 2)
			mlx_string_put(ml->mlx, ml->win, 20, 12, 0x00FF0000, "YOU WIN");
		else
			mlx_string_put(ml->mlx, ml->win, 20, 12, 0x00FF0000, "YOU LOOSE");
	}
	return (1);
}

void	get_end(t_mlx *ml)
{
	if (!isany(ml, 'C'))
	{
		if (isany(ml, 'E'))
		{
			replace1(ml, 'E', 'e');
			ml->anim++;
		}
	}
	if (!isany(ml, 'E') && !isany(ml, 'e'))
		ml->gameover = 2;
}

void	animate(t_mlx *ml)
{
	void	(*hro_mv[5])(t_mlx *m, int (*f)(void *, void *, void *, int, int));
	void	(*foe_mv[5])(t_mlx *m, int (*f)(void *, void *, void *, int, int));

	load_fx_mv(hro_mv, foe_mv);
	//mlx_clear_window(ml->mlx, ml->win);
	put_background(ml, &mlx_put_image_to_window);
	if (ml->foe.exist)
		get_foe_mv(ml);
	if (!put_score(ml))
		custom_exit(ml);
	hro_mv[ml->hro.mv](ml, &mlx_put_image_to_window);
	if (ml->foe.exist)
		foe_mv[ml->foe.mv](ml, &mlx_put_image_to_window);
	get_end(ml);
	if (ml->foe.wait > 0)
		ml->foe.wait--;
}
	/*printf("BEFORE waiting : %d ml->rnd : %d prev : %d foe.mv : %d foe.bsy/
	: %d\n", ml->foe.wait,  ml->rnd, ml->foe.pmv, ml->foe.mv, ml->foe.bsy);*/
