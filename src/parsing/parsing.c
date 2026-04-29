/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:00:50 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/19 22:00:50 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_only_spaces(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	remove_nl(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0')
		return ;
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\r' || line[i] < 32)
			line[i] = '\0';
		i++;
	}
}

static int	all_set(t_arg *data)
{
	return (data->no && data->so && data->we && data->ea
		&& data->map && data->f_defined && data->c_defined);
}

static void	parsing_helper(char *line, t_arg *data)
{
	if (is_texture(line))
		parse_texture(line, data);
	else if (is_color(line))
		parse_color(line, data);
	else if (is_map_line(line))
		add_to_map(line, data);
}

int	parsing(char *file, t_arg *data)
{
	int		fd;
	char	*line;
	int		map_started;

	map_started = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		remove_nl(line);
		if (map_started && is_only_spaces(line))
			return (free_close(line, fd), 0);
		if (!is_only_spaces(line))
		{
			if (!map_started)
			{
				if (is_map_line(line))
				{
					map_started = 1;
					add_to_map(line, data);
				}
				else
					parsing_helper(line, data);
			}
			else
			{
				if (!is_map_line(line))
					return (free_close(line, fd), 0);
				add_to_map(line, data);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!all_set(data))
		return (0);
	return (1);
}
