/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/21 17:39:34 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	t_mlx	ml;

	if (ac != 2)
		return (0);

	init_mlx_struct(&ml,"So Long Mother****er", av[1]);
	mlx_hook(ml.win, 2, 1L << 0, treat_press, &ml);
	mlx_hook(ml.win, 4, 1L << 2, treat_click, &ml);
	mlx_loop_hook(ml.mlx, render, &ml);
	mlx_loop(ml.mlx);

	return (0);
}
