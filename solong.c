/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/20 19:06:36 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdio.h>
#include <stdlib.h>

int	treat_press(int keycode, t_mlx *mlx)
{
//	printf("keycode >%d<\n", keycode);
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

int	treat_click(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf("button keycode >%d<\n", keycode);

	return (0);
}

void	idle_pers(t_mlx *ml, int (*f)(void *, void *, void *, int, int))
{
	if (ml->hro.mv == 0 && !ml->hro.rev)
		f(ml->mlx, ml->win, ml->hro.idl[ml->rnd % 6], ml->hro.x, ml->hro.y);
	if (ml->hro.mv == 0 && ml->hro.rev)
		f(ml->mlx, ml->win, ml->hro.ridl[ml->rnd % 6], ml->hro.x, ml->hro.y);
}

void	animate(t_mlx *ml)
{
	t_mlx_fx_img_to_win	fx;

	fx = &mlx_put_image_to_window;
	mlx_clear_window(ml->mlx, ml->win);
	idle_pers(ml, mlx_put_image_to_window);

	if (ml->hro.mv == 'r') // && ml->hro.bsy != -1)
	{
		if (ml->hro.bsy == 0)
			ml->hro.x += (1*4);
		ml->hro.x += (3*4);
		fx(ml->mlx, ml->win, ml->hro.run[ml->hro.bsy], ml->hro.x, ml->hro.y);
		ml->hro.bsy++;
		if (ml->hro.bsy == 6)
		{
			ml->hro.mv = 0;
			ml->hro.bsy = -1;
			ml->hro.rev = 0;
		}
	}
	if (ml->hro.mv == 'l')// && ml->hro.bsy != -1)
	{
		if (ml->hro.bsy == 0)
			ml->hro.x -= (1*4);
		ml->hro.x -= (3*4);
		fx(ml->mlx, ml->win, ml->hro.rrun[ml->hro.bsy], ml->hro.x, ml->hro.y);
		ml->hro.bsy++;
		if (ml->hro.bsy == 6)
		{
			ml->hro.mv = 0;
			ml->hro.bsy = -1;
			ml->hro.rev = 1;
		}
	}
	if (ml->hro.mv == 'u')// && ml->hro.bsy != -1)
	{
		if (ml->hro.bsy == 0)
			ml->hro.y -= (1*4);
		ml->hro.y -= (3*4);
		if (ml->hro.rev)
			fx(ml->mlx, ml->win, ml->hro.rrun[ml->hro.bsy], ml->hro.x, ml->hro.y);
		else
			fx(ml->mlx, ml->win, ml->hro.run[ml->hro.bsy], ml->hro.x, ml->hro.y);
		ml->hro.bsy++;
		if (ml->hro.bsy == 6)
		{
			ml->hro.mv = 0;
			ml->hro.bsy = -1;
		}
	}
	if (ml->hro.mv == 'd') // && ml->hro.bsy != -1)
	{
		if (ml->hro.bsy == 0)
			ml->hro.y += (1*4);
		ml->hro.y += (3*4);
		if (ml->hro.rev)
			fx(ml->mlx, ml->win, ml->hro.rrun[ml->hro.bsy], ml->hro.x, ml->hro.y);
		else
			fx(ml->mlx, ml->win, ml->hro.run[ml->hro.bsy], ml->hro.x, ml->hro.y);
		ml->hro.bsy++;
		if (ml->hro.bsy == 6)
		{
			ml->hro.mv = 0;
			ml->hro.bsy = -1;
		}
	}
}

int	render(t_mlx *ml)
{
	if (ml->timer == 512)
	{
		//printf("Time to render\n");
		ml->timer = 0;
		ml->rnd++;
		animate(ml);
	}
	ml->timer++;
	return (0);
}

void	init_mlx_struct(t_mlx *ml, int width, int height, char *name)
{
	t_mlx_fx_xpmf_to_img	fx;

	fx = &mlx_xpm_file_to_image;
	ml->timer = 0;
	ml->rnd = 0;
	ml->hro.x = 0;
	ml->hro.y = 0;
	ml->hro.mv = 0;
	ml->hro.rev = 0;
	ml->mlx = mlx_init();
	ml->win = mlx_new_window(ml->mlx, width, height, name);
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

int	main(void)
{
	t_mlx					ml;

	init_mlx_struct(&ml, 640, 640, "So Long Mother****er");
	load_hero_img(&ml, mlx_xpm_file_to_image);

	mlx_hook(ml.win, 2, 1L << 0, treat_press, &ml);
	mlx_hook(ml.win, 4, 1L << 2, treat_click, &ml);
	mlx_loop_hook(ml.mlx, render, &ml);
	mlx_loop(ml.mlx);
	return (0);
}
