/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:14:11 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/20 18:15:02 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

typedef struct s_pers {
	int		w;
	int		h;
	int		x;
	int		y;
	int		mv;
	int		bsy;
	int		rev;
	void	*idl[6];
	void	*ridl[6];
	void	*run[6];
	void	*rrun[6];
}			t_pers;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		timer;
	int		rnd;
	t_pers	hro;
	t_pers	foe;
}			t_mlx;

typedef int		(*t_mlx_fx_img_to_win)(void *, void *, void *, int, int);

typedef void	*(*t_mlx_fx_xpmf_to_img)(void *, char *, int *, int *);
#endif
