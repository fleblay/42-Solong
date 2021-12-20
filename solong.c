/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/20 12:49:38 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdio.h>
#include <stdlib.h>

int	close_win(int keycode, t_mlx *mlx)
{
	printf("keycode >%d<\n", keycode);
	//if (keycode == 2)
	//	mlx->hro.x += 16;
	//if (keycode == 0)
	//	mlx->hro.x -= 16;
	//if (keycode == 1)
	//	mlx->hro.y += 16;
	//if (keycode == 13)
	//	mlx->hro.y -= 16;
	if (keycode == 2)
		mlx->hro.mv = 'r';
	if (keycode == 0)
		mlx->hro.mv = 'l';
	if (keycode == 1)
		mlx->hro.mv = 'd';
	if (keycode == 13)
		mlx->hro.mv = 'u';
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	button(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf("button keycode >%d<\n", keycode);
	return (0);
}

void	movepnj(t_mlx *mlx)
{
	t_mlx_fx_img_to_win	fx;

	fx = &mlx_put_image_to_window;
	//mlx->hro.x += 16;
	mlx_clear_window(mlx->mlx, mlx->win);
	if (mlx->hro.mv == 0)
		fx(mlx->mlx, mlx->win, mlx->hro.d_id[mlx->render % 6], mlx->hro.x, mlx->hro.y);
	if (mlx->hro.mv == 'r')
		fx(mlx->mlx, mlx->win, mlx->hro.u_id[mlx->render % 6], mlx->hro.x, mlx->hro.y);
}

int	render(t_mlx *mlx)
{
	if (mlx->timer == 1024)
	{
		printf("Time to render\n");
		mlx->timer -= 1024;
		mlx->render++;
		movepnj(mlx);
	}
	mlx->timer++;
	return (0);
}

int	main(void)
{
	t_mlx					mlx;
	t_mlx_fx_xpmf_to_img	fx;

	fx = &mlx_xpm_file_to_image;
	mlx.timer = 0;
	mlx.render = 0;
	//mlx.hro.pth = "./knight.xpm";
	mlx.hro.x = 0;
	mlx.hro.y = 0;
	mlx.hro.mv = 0;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 600, "My window");
	mlx.hro.d_id[0] = fx(mlx.mlx, "./img/knight_idle_anim_f0.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.d_id[1] = fx(mlx.mlx, "./img/knight_idle_anim_f1.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.d_id[2] = fx(mlx.mlx, "./img/knight_idle_anim_f2.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.d_id[3] = fx(mlx.mlx, "./img/knight_idle_anim_f3.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.d_id[4] = fx(mlx.mlx, "./img/knight_idle_anim_f4.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.d_id[5] = fx(mlx.mlx, "./img/knight_idle_anim_f5.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.u_id[0] = fx(mlx.mlx, "./img/knight_run_anim_f0.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.u_id[1] = fx(mlx.mlx, "./img/knight_run_anim_f1.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.u_id[2] = fx(mlx.mlx, "./img/knight_run_anim_f2.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.u_id[3] = fx(mlx.mlx, "./img/knight_run_anim_f3.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.u_id[4] = fx(mlx.mlx, "./img/knight_run_anim_f4.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.u_id[5] = fx(mlx.mlx, "./img/knight_run_anim_f5.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx_hook(mlx.win, 2, 1L << 0, close_win, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, button, &mlx);
	mlx_loop_hook(mlx.mlx, render, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
