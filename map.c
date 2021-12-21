/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:12:40 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/21 19:10:38 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

int getmap(char *str, t_mlx *ml)
{
	int		fd;
	char	buf[1000000 + 1];
	int		ret;

	fd = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buf, 1000000);
	if (ret <= 0)
		return (0);
	buf[ret] = '\0';
	ml->map = ft_split(buf, '\n');
	set_size(ml);
	set_hro_pos(ml);
	return (1);
}

void	set_size(t_mlx *ml)
{
	int	i;
	
	i = 0;
	ml->mapw = ft_strlen(ml->map[0]);
	while (ml->map[i])
	{
		i++;
	}
	ml->maph = i;
	printf("mapw : %d, maph : %d, flow : %d, floh : %d\n", ml->mapw, ml->maph, ml->flow, ml->floh);
}

void	set_hro_pos(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P')
			{
				ml->hro.x = j * ml->hro.w;
				ml->hro.y = i * ml->hro.h;
			}
			j++;
		}
		i++;
	}
}

int		r_isnotwall(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P' && ml->map[i][j + 1] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		l_isnotwall(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P' && ml->map[i][j - 1] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		u_isnotwall(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P' && ml->map[i - 1][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		d_isnotwall(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P' && ml->map[i + 1][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	mv_hro_right(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P')
			{
				ml->map[i][j] = '0';
				ml->map[i][j + 1] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mv_hro_left(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P')
			{
				ml->map[i][j] = '0';
				ml->map[i][j - 1] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mv_hro_up(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P')
			{
				ml->map[i][j] = '0';
				ml->map[i - 1][j] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mv_hro_down(t_mlx *ml)
{
	int	i;
	int	j;

	i = 0;
	while (i < ml->maph)
	{
		j = 0;
		while (j < ml->mapw)
		{
			if (ml->map[i][j] == 'P')
			{
				ml->map[i][j] = '0';
				ml->map[i + 1][j] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}
