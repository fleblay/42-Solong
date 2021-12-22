/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:14:11 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 12:55:57 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

typedef struct s_pers {
	char	c;
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
	char	**map;
	int		maph;
	int		mapw;

	void	*wal;
	int		walh;
	int		walw;

	void	*flo;
	int		floh;
	int		flow;

	void	*col;
	int		colh;
	int		colw;

	void	*exi;
	int		exih;
	int		exiw;

	void	*out;
	int		outh;
	int		outw;

}			t_mlx;

enum	{idle = 0, right = 1 , left = 2, up = 3, down = 4};
void	idle_pers(t_mlx *ml, int (*f)(void *, void *, void *, int, int));
void	mv_right(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_left(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_up(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_down(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	init_mlx_struct(t_mlx *ml, char *name, char *file);
void	load_hero_img(t_mlx *ml, void *(*f)(void *, char *, int *, int *));
void	load_foe_img(t_mlx *ml, void *(*f)(void *, char *, int *, int *));
void	load_map_img(t_mlx *ml, void *(*f)(void *, char *, int *, int *));
int		treat_press(int keycode, t_mlx *mlx);
int		treat_click(int keycode, t_mlx *mlx);
void	animate(t_mlx *ml);
int		render(t_mlx *ml);
int		getmap(char *str, t_mlx *ml);
void	set_size(t_mlx *ml);
void	set_hro_pos(t_mlx *ml);
char	r_is(t_mlx *ml, char pers_char);
char	l_is(t_mlx *ml, char pers_char);
char	d_is(t_mlx *ml, char pers_char);
char	u_is(t_mlx *ml, char pers_char);
void	mv_r(t_mlx *ml, char pers_char);
void	mv_l(t_mlx *ml, char pers_char);
void	mv_u(t_mlx *ml, char pers_char);
void	mv_d(t_mlx *ml, char pers_char);
int		mv_ok(t_mlx *ml, int move, char pers_char);
int		isany(t_mlx *ml, char pers_char);
int		replace1(t_mlx *ml, char old, char nw);

#endif
