/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:14:11 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/29 10:24:01 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# if defined(OLD)
#  define KEY_R 2
#  define KEY_L 0
#  define KEY_D 1
#  define KEY_U 13
#  define KEY_ESC 53
#  define SPEED 256
#  define KILL_DISPLAY 0
#  define BONUS 0
# elif defined(OLDBONUS)
#  define KEY_R 2
#  define KEY_L 0
#  define KEY_D 1
#  define KEY_U 13
#  define KEY_ESC 53
#  define SPEED 256
#  define KILL_DISPLAY 0
#  define BONUS 1
# elif defined(NEWBONUS)
#  define KEY_R 100
#  define KEY_L 97
#  define KEY_D 115
#  define KEY_U 119
#  define KEY_ESC 65307
#  define SPEED 1200
#  define KILL_DISPLAY 1
#  define BONUS 1
# else
#  define KEY_R 100
#  define KEY_L 97
#  define KEY_D 115
#  define KEY_U 119
#  define KEY_ESC 65307
#  define SPEED 1200
#  define KILL_DISPLAY 1
#  define BONUS 0
# endif

typedef struct s_pers {
	char	c;
	int		w;
	int		h;
	int		x;
	int		y;
	int		mv;
	int		bsy;
	int		rev;
	int		pmv;
	int		wait;
	int		steps;
	int		exist;
	void	*idl[6];
	void	*ridl[6];
	void	*run[6];
	void	*rrun[6];
}			t_pers;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		error;
	int		timer;
	int		rnd;
	t_pers	hro;
	t_pers	foe;
	char	**map;
	int		maph;
	int		mapw;
	int		gameover;

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

	void	*out2[15];
	int		out2h;
	int		out2w;
	int		anim;

}			t_mlx;

enum	{idle = 0, right = 1 , left = 2, up = 3, down = 4};
void	idle_pers(t_mlx *ml, int (*f)(void *, void *, void *, int, int));
void	mv_right(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_left(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_up(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_down(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	idle_persfoe(t_mlx *ml, int (*f)(void *, void *, void *, int, int));
void	mv_rightfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_leftfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_upfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	mv_downfoe(t_mlx *ml, int (*fx)(void *, void *, void *, int, int));
void	init_pers(t_pers *pers, char pers_char);
void	init_mlx_struct(t_mlx *ml);
void	set_mlx_struct(t_mlx *ml, char *name, char *file);
void	*custom_load_xpm(t_mlx *ml, char *path, int *w, int *h);
void	load_hero_img(t_mlx *ml, void *(*f)(t_mlx *, char *, int *, int *));
void	load_foe_img(t_mlx *ml, void *(*f)(t_mlx *, char *, int *, int *));
void	load_map_img(t_mlx *ml, void *(*f)(t_mlx *, char *, int *, int *));
void	custom_destroy_img(void *mlx, void *img);
void	destroy_images(t_mlx *ml);
void	print_error(t_mlx *ml);
int		custom_exit(t_mlx *ml);
int		treat_press(int keycode, t_mlx *ml);
void	get_foe_mv(t_mlx *ml);
void	put_background(t_mlx *ml, int (*f)(void *, void *, void *, int, int));
int		put_score(t_mlx *ml);
void	load_fx_mv(void (*tab1[])(), void (*tab2[])());
void	get_end(t_mlx *ml);
void	animate(t_mlx *ml);
int		render(t_mlx *ml);
int		getmap(char *str, t_mlx *ml);
void	set_size(t_mlx *ml);
void	set_pers_pos(t_mlx *ml, t_pers *pers);
int		check_valid_char(char *s);
int		check_only_1(char *s);
int		check_1and1(char *s);
int		nb_of(char **map, char c);
int		check_mapname(char *s);
int		get_error(t_mlx *ml);
char	r_is(t_mlx *ml, char pers_char);
char	l_is(t_mlx *ml, char pers_char);
char	d_is(t_mlx *ml, char pers_char);
char	u_is(t_mlx *ml, char pers_char);
void	mv_r(t_mlx *ml, char pers_char);
void	mv_l(t_mlx *ml, char pers_char);
void	mv_u(t_mlx *ml, char pers_char);
void	mv_d(t_mlx *ml, char pers_char);
int		mv_nok(t_mlx *ml, int move, char pers_char);
int		isany(t_mlx *ml, char pers_char);
int		replace1(t_mlx *ml, char old, char nw);

#endif
