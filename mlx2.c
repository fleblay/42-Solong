/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:49:14 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/23 18:14:45 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include <stdlib.h>
#include <stdio.h>

void	custom_exit(t_mlx *ml)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		free (ml->hro.idl[i]);
		free (ml->hro.ridl[i]);
		free (ml->hro.run[i]);
		free (ml->hro.rrun[i]);
		free (ml->foe.idl[i]);
		free (ml->foe.ridl[i]);
		free (ml->foe.run[i]);
		free (ml->foe.rrun[i]);
		free(ml->out2[i]);
	}
	while (i < 15)
		free(ml->out2[i++]);
	free(ml->map);
	free(ml->flo);
	free(ml->wal);
	free(ml->exi);
	free(ml->col);
	mlx_destroy_window(ml->mlx, ml->win);
	free(ml->mlx);
	exit(0);
}
/* Free tout sauf la win qui est destroy par la fonction ad-hoc */
