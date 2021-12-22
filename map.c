/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:12:40 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/22 10:01:41 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

int	getmap(char *str, t_mlx *ml)
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
		i++;
	ml->maph = i;
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
