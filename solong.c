/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/20 16:19:57 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdio.h>
#include <stdlib.h>

int	close_win(int keycode, t_mlx *mlx)
{
	printf("keycode >%d<\n", keycode);
	if (keycode == 2 && !mlx->hro.mv)
	{
		mlx->hro.mv = 'r';
		mlx->hro.bsy = 0;
	}
	if (keycode == 0 && !mlx->hro.mv)
	{
		mlx->hro.mv = 'l';
		mlx->hro.bsy = 0;
	}
	if (keycode == 1 && !mlx->hro.mv)
	{
		mlx->hro.mv = 'd';
		mlx->hro.bsy = 0;
	}
	if (keycode == 13 && !mlx->hro.mv)
	{
		mlx->hro.mv = 'u';
		mlx->hro.bsy = 0;
	}
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
	mlx_clear_window(mlx->mlx, mlx->win);
	if (mlx->hro.mv == 0 && !mlx->hro.rev)
		fx(mlx->mlx, mlx->win, mlx->hro.idl[mlx->render % 6], mlx->hro.x, mlx->hro.y);
	if (mlx->hro.mv == 0 && mlx->hro.rev)
		fx(mlx->mlx, mlx->win, mlx->hro.ridl[mlx->render % 6], mlx->hro.x, mlx->hro.y);
	if (mlx->hro.mv == 'r' && mlx->hro.bsy != -1)
	{
		if (mlx->hro.bsy == 0)
			mlx->hro.x += (1*4);
		mlx->hro.x += (3*4);
		fx(mlx->mlx, mlx->win, mlx->hro.run[mlx->hro.bsy], mlx->hro.x, mlx->hro.y);
		mlx->hro.bsy++;
		if (mlx->hro.bsy == 6)
		{
			mlx->hro.mv = 0;
			mlx->hro.bsy = -1;
			mlx->hro.rev = 0;
		}
	}
	if (mlx->hro.mv == 'l' && mlx->hro.bsy != -1)
	{
		if (mlx->hro.bsy == 0)
			mlx->hro.x -= (1*4);
		mlx->hro.x -= (3*4);
		fx(mlx->mlx, mlx->win, mlx->hro.rrun[mlx->hro.bsy], mlx->hro.x, mlx->hro.y);
		mlx->hro.bsy++;
		if (mlx->hro.bsy == 6)
		{
			mlx->hro.mv = 0;
			mlx->hro.bsy = -1;
			mlx->hro.rev = 1;
		}
	}
	if (mlx->hro.mv == 'u' && mlx->hro.bsy != -1)
	{
		if (mlx->hro.bsy == 0)
			mlx->hro.y -= (1*4);
		mlx->hro.y -= (3*4);
		if (mlx->hro.rev)
			fx(mlx->mlx, mlx->win, mlx->hro.rrun[mlx->hro.bsy], mlx->hro.x, mlx->hro.y);
		else
			fx(mlx->mlx, mlx->win, mlx->hro.run[mlx->hro.bsy], mlx->hro.x, mlx->hro.y);
		mlx->hro.bsy++;
		if (mlx->hro.bsy == 6)
		{
			mlx->hro.mv = 0;
			mlx->hro.bsy = -1;
		}
	}
	if (mlx->hro.mv == 'd' && mlx->hro.bsy != -1)
	{
		if (mlx->hro.bsy == 0)
			mlx->hro.y += (1*4);
		mlx->hro.y += (3*4);
		if (mlx->hro.rev)
			fx(mlx->mlx, mlx->win, mlx->hro.rrun[mlx->hro.bsy], mlx->hro.x, mlx->hro.y);
		else
			fx(mlx->mlx, mlx->win, mlx->hro.run[mlx->hro.bsy], mlx->hro.x, mlx->hro.y);
		mlx->hro.bsy++;
		if (mlx->hro.bsy == 6)
		{
			mlx->hro.mv = 0;
			mlx->hro.bsy = -1;
		}
	}
}

int	render(t_mlx *mlx)
{
	if (mlx->timer == 512)
	{
		printf("Time to render\n");
		mlx->timer = 0;
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
	mlx.hro.x = 0;
	mlx.hro.y = 0;
	mlx.hro.mv = 0;
	mlx.hro.rev = 0;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 600, "My window");
	mlx.hro.idl[0] = fx(mlx.mlx, "./img/big_knight_idle_anim_f0.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.idl[1] = fx(mlx.mlx, "./img/big_knight_idle_anim_f1.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.idl[2] = fx(mlx.mlx, "./img/big_knight_idle_anim_f2.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.idl[3] = fx(mlx.mlx, "./img/big_knight_idle_anim_f3.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.idl[4] = fx(mlx.mlx, "./img/big_knight_idle_anim_f4.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.idl[5] = fx(mlx.mlx, "./img/big_knight_idle_anim_f5.xpm", &(mlx.hro.w), &(mlx.hro.h));

	mlx.hro.ridl[0] = fx(mlx.mlx, "./img/revbig_knight_idle_anim_f0.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.ridl[1] = fx(mlx.mlx, "./img/revbig_knight_idle_anim_f1.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.ridl[2] = fx(mlx.mlx, "./img/revbig_knight_idle_anim_f2.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.ridl[3] = fx(mlx.mlx, "./img/revbig_knight_idle_anim_f3.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.ridl[4] = fx(mlx.mlx, "./img/revbig_knight_idle_anim_f4.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.ridl[5] = fx(mlx.mlx, "./img/revbig_knight_idle_anim_f5.xpm", &(mlx.hro.w), &(mlx.hro.h));

	mlx.hro.run[0] = fx(mlx.mlx, "./img/big_knight_run_anim_f0.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.run[1] = fx(mlx.mlx, "./img/big_knight_run_anim_f1.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.run[2] = fx(mlx.mlx, "./img/big_knight_run_anim_f2.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.run[3] = fx(mlx.mlx, "./img/big_knight_run_anim_f3.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.run[4] = fx(mlx.mlx, "./img/big_knight_run_anim_f4.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.run[5] = fx(mlx.mlx, "./img/big_knight_run_anim_f5.xpm", &(mlx.hro.w), &(mlx.hro.h));

	mlx.hro.rrun[0] = fx(mlx.mlx, "./img/revbig_knight_run_anim_f0.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.rrun[1] = fx(mlx.mlx, "./img/revbig_knight_run_anim_f1.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.rrun[2] = fx(mlx.mlx, "./img/revbig_knight_run_anim_f2.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.rrun[3] = fx(mlx.mlx, "./img/revbig_knight_run_anim_f3.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.rrun[4] = fx(mlx.mlx, "./img/revbig_knight_run_anim_f4.xpm", &(mlx.hro.w), &(mlx.hro.h));
	mlx.hro.rrun[5] = fx(mlx.mlx, "./img/revbig_knight_run_anim_f5.xpm", &(mlx.hro.w), &(mlx.hro.h));

	mlx_hook(mlx.win, 2, 1L << 0, close_win, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, button, &mlx);
	mlx_loop_hook(mlx.mlx, render, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
