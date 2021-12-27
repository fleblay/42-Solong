/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:12:40 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/27 13:11:38 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>
#include <errno.h>

int	getmap(char *str, t_mlx *ml)
{
	int		fd;
	char	buf[1000000 + 1];
	int		ret;

	fd = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		custom_exit(ml);
	ret = read(fd, buf, 1000000);
	if (ret <= 0)
		custom_exit(ml);
	buf[ret] = '\0';
	ml->map = ft_split(buf, '\n');
	if (!ml->map)
		custom_exit(ml);
	set_size(ml);
	if (get_error(ml))
		custom_exit(ml);
	set_pers_pos(ml, &(ml->hro));
	set_pers_pos(ml, &(ml->foe));
	return (1);
}

void	set_size(t_mlx *ml)
{
	int	i;

	i = 0;
	ml->mapw = ft_strlen(ml->map[0]);
	while (ml->map[i])
		i++;
	ml->maph = i;
}

void	set_pers_pos(t_mlx *ml, t_pers *pers)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == pers->c)
			{
				pers->x = j * pers->w;
				pers->y = i * pers->h;
				pers->exist = 1;
			}
			j++;
		}
		i++;
	}
}

int	check_valid_char(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'C' && s[i] != 'E'
				&& s[i] != 'P' && ((!BONUS) + BONUS * s[i]!= 'F'))
			return (0);
		i++;
	}
	return (1);
}

int	get_error(t_mlx *ml)
{
	int error;
	int i;

	i = 0;
	error = 0;
	while (ml->map[i])
	{
		if ((int)ft_strlen(ml->map[i]) != ml->mapw)
			error = error | 1;
		if (!check_valid_char(ml->map[i]))
			error += 1 << 1;
		i++;
	}
	printf("error : %d\n", error);
	return (error);
}
