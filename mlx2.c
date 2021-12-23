/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:49:14 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/23 16:29:49 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdlib.h>

void	custom_exit(t_mlx *ml)
{
	//IMG destroy to be done !
	mlx_destroy_window(ml->mlx, ml->win);
	exit(0);
}
