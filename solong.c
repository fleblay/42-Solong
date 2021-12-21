/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/21 12:07:54 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

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
