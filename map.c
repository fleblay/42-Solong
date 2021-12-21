/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:12:40 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/21 12:37:43 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	**getmap(char *str)
{
	char	**map;
	int		fd;
	char	buf[1000000 + 1];
	int		ret;

	fd = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, 1000000);
	if (ret <= 0)
		return (NULL);
	buf[ret] = '\0';
	map = ft_split(buf, '\n');
	return (map);
}

