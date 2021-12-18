/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/17 16:06:20 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include "keysymdef.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		timer;;
}			t_mlx;

int close_win(int keycode, t_mlx *mlx)
{
	printf("keycode >%d<\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int button(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf("button keycode >%d<\n", keycode);
	return (0);
}

int	render(t_mlx *mlx)
{
	static int i = 0;
	if (i == 2400)
	{
		printf("Time : %d\n", mlx->timer);
		i -= 2400;
		mlx->timer++;
	}
	i++;
	return (0);
}

/*int mouseh(int keycode, t_mlx *mlx)
{
	(void)keycode;
	printf("ici\n");
	mlx_mouse_get_pos(mlx->win, &(mlx->mousex), &(mlx->mousey));
	printf("la\n");
	printf("mouse x : >%d< mouse y : >%d<\n", mlx->mousex, mlx->mousey);
	return (0);
}*/

int main(void)
{
	t_mlx	mlx;
	mlx.timer = 0;
	void	*img;
	char 	*path;
	int		width;
	int		height;

	path = "./knight.xpm";
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 600, "My window");
	img = mlx_xpm_file_to_image(mlx.mlx, path, &width, &height);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	mlx_hook(mlx.win, 4, 1L<<2, button, &mlx);
//	mlx_hook(mlx.win, 6, 0L, mouseh, &mlx);
	mlx_loop_hook(mlx.mlx, render, &mlx);
//	mlx_loop_hook(mlx.mlx, move, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
