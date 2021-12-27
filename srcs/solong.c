/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:17:37 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/27 16:43:09 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stddef.h>

int	main(int ac, char *av[])
{
	t_mlx	ml;

	ml.win = NULL;
	ml.mlx = NULL;
	if (ac != 2)
		return (0);
	set_mlx_struct(&ml, "So Long Mother****er", av[1]);
	mlx_hook(ml.win, 2, 1L << 0, &treat_press, &ml);
	mlx_hook(ml.win, 17, 1L << 1, &custom_exit, &ml);
	mlx_loop_hook(ml.mlx, render, &ml);
	mlx_loop(ml.mlx);
	return (0);
}
