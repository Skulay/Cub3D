/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:07:35 by tkhider           #+#    #+#             */
/*   Updated: 2026/04/22 21:29:41 by tkhider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	return (0);
}

static int	is_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	check_surroundings(char **map, int y, int x, int max_y)
{
	int	len_prev;
	int	len_next;

	if (y == 0 || y == max_y - 1 || x == 0)
		return (0);
	len_prev = ft_strlen(map[y - 1]);
	len_next = ft_strlen(map[y + 1]);
	if (x >= len_prev || x >= len_next)
		return (0);
	if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		return (0);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
		return (0);
	return (1);
}

int	validate_map(t_arg *data)
{
	int	y;
	int	x;
	int	p;

	y = -1;
	p = 0;
	while (++y < data->map_size)
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (!is_valid_char(data->map[y][x]))
				return (0);
			if (is_walkable(data->map[y][x]) && data->map[y][x] != '0')
				p++;
			if (is_walkable(data->map[y][x]))
				if (!check_surroundings(data->map, y, x, data->map_size))
					return (0);
		}
	}
	return (p == 1);
}
