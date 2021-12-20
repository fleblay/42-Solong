/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/20 11:16:06 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdio.h>
#include <stdlib.h>

int	close_win(int keycode, t_mlx *mlx)
{
	printf("keycode >%d<\n", keycode);
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
	mlx->hro.x += 16;
	mlx_clear_window(mlx->mlx, mlx->win);
	fx(mlx->mlx, mlx->win, mlx->hro.img, mlx->hro.x, mlx->hro.y);
}

int	render(t_mlx *mlx)
{
	if (mlx->timer == 2048)
	{
		printf("Time to render\n");
		mlx->timer -= 2048;
		mlx->render = 1;
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
	mlx.hro.pth = "./knight.xpm";
	mlx.hro.x = 0;
	mlx.hro.y = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 600, "My window");
	mlx.hro.img = fx(mlx.mlx, mlx.hro.pth, &(mlx.hro.w), &(mlx.hro.h));
	mlx_hook(mlx.win, 2, 1L << 0, close_win, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, button, &mlx);
	mlx_loop_hook(mlx.mlx, render, &mlx);
<<<<<<< HEAD
=======
//	mlx_loop_hook(mlx.mlx, move, &mlx);
>>>>>>> 39a74fbb4992ecbb9a04b5d9478a6d72048cd211
	mlx_loop(mlx.mlx);
	return (0);
}
