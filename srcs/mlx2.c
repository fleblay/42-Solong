/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:49:14 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/29 10:28:19 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdlib.h>
#include <stdio.h>

void	custom_destroy_img(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

void	destroy_images(t_mlx *ml)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		custom_destroy_img(ml->mlx, ml->hro.idl[i]);
		custom_destroy_img(ml->mlx, ml->hro.ridl[i]);
		custom_destroy_img(ml->mlx, ml->hro.run[i]);
		custom_destroy_img(ml->mlx, ml->hro.rrun[i]);
		custom_destroy_img(ml->mlx, ml->foe.idl[i]);
		custom_destroy_img(ml->mlx, ml->foe.ridl[i]);
		custom_destroy_img(ml->mlx, ml->foe.run[i]);
		custom_destroy_img(ml->mlx, ml->foe.rrun[i]);
		custom_destroy_img(ml->mlx, ml->out2[i]);
	}
	while (i < 15)
		custom_destroy_img(ml->mlx, ml->out2[i++]);
	custom_destroy_img(ml->mlx, ml->flo);
	custom_destroy_img(ml->mlx, ml->wal);
	custom_destroy_img(ml->mlx, ml->exi);
	custom_destroy_img(ml->mlx, ml->col);
}

void	print_error(t_mlx *ml)
{
	if (ml->error)
	{
		printf("Error\n");
		(ml->error & 1) && printf("Wrong map filename\n");
		(ml->error & 1 << 1) && printf("Map is not rectangular\n");
		(ml->error & 1 << 2) && printf("Map has invalid characters\n");
		(ml->error & 1 << 3) && printf("Map is not surrounded by walls\n");
		(ml->error & 1 << 4) && printf("Map must have at least one exit, one ");
		(ml->error & 1 << 4) && printf("collectible and one starting ");
		(ml->error & 1 << 4) && printf("position\n");
		(ml->error & 1 << 5) && printf("Too many player starting positions\n");
		(ml->error & 1 << 6) && printf("Too many exits\n");
	}
}

int	custom_exit(t_mlx *ml)
{
	int	i;

	i = 0;
	destroy_images(ml);
	if (ml->win)
		mlx_destroy_window(ml->mlx, ml->win);
	if (ml->map)
		while (ml->map[i])
			free(ml->map[i++]);
	free (ml->map);
	KILL_DISPLAY && mlx_destroy_display(ml->mlx);
	free(ml->mlx);
	print_error(ml);
	exit(0);
	return (0);
}
