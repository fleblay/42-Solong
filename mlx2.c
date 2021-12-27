/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:49:14 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/27 12:22:34 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdlib.h>
#include <stdio.h>

void	custom_destroy_img(void *mlx, void *img)
{
	if (img)
	{
		mlx_destroy_image(mlx, img);
		img = NULL;
	}
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
	custom_destroy_img(ml->mlx, ml->map);
	custom_destroy_img(ml->mlx, ml->flo);
	custom_destroy_img(ml->mlx, ml->wal);
	custom_destroy_img(ml->mlx, ml->exi);
	custom_destroy_img(ml->mlx, ml->col);
}

int	custom_exit(t_mlx *ml)
{
	destroy_images(ml);
	if (ml->win)
		mlx_destroy_window(ml->mlx, ml->win);
	free(ml->mlx);
	//char *ptr = malloc(sizeof(char) * 7);
	//(void)ptr;
	exit(0);
	return (0);
}
