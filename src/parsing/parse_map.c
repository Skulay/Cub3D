/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:30:54 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/20 07:30:54 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	char_map_line(char c)
{
	if (c == '0' || c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (!char_map_line(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	add_to_map(char *line, t_arg *data)
{
	if (data->map_size >= MAX_MAP_SIZE)
	{
		err_msg("map is full");
		return (0);
	}
	data->map[data->map_size] = ft_strdup(line);
	if (!data->map[data->map_size])
		return (0);
	data->map_size++;
	data->map[data->map_size] = NULL;
	return (1);
}
