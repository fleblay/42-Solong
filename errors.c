/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:14:18 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/27 16:41:08 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solong.h"

int	check_valid_char(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'C' && s[i] != 'E'
			&& s[i] != 'P' && ((!BONUS) + BONUS * s[i] != 'F'))
			return (0);
		i++;
	}
	return (1);
}

int	check_only_1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_1and1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[0] != '1')
		return (0);
	while (s[i])
		i++;
	if (s[--i] != '1')
		return (0);
	return (1);
}

int	nb_of(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count ++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_mapname(char *s)
{
	if (!s)
		return (0);
	if (ft_strlen(s) < 5)
		return (0);
	if (ft_strncmp(s + ft_strlen(s) - 4, ".ber", ft_strlen(s)))
		return (0);
	return (1);
}
