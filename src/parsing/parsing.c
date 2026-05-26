/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:00:50 by alehamad          #+#    #+#             */
/*   Updated: 2026/05/26 22:58:09 by tkhider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	parsing_helper(char *line, t_arg *data)
{
	if (is_texture(line))
		parse_texture(line, data);
	else if (is_color(line))
		parse_color(line, data);
	else if (is_map_line(line))
		add_to_map(line, data);
}

static int	handle_line(char *line, t_arg *data, int *map_started)
{
	if (is_only_spaces(line))
		return (!*map_started);
	if (!*map_started && is_map_line(line))
		*map_started = 1;
	if (*map_started)
	{
		if (!is_map_line(line))
			return (0);
		add_to_map(line, data);
	}
	else
		parsing_helper(line, data);
	return (1);
}
static void	purge_gnl_buffer(int fd, char *current_line)
{
	if (!current_line)
		return ;
	do
	{
		free(current_line);
		current_line = get_next_line(fd);
	} while (NULL != current_line);
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
		if (!handle_line(line, data, &map_started))
		{
			purge_gnl_buffer(fd, line);
			return (close(fd), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!all_set(data) || !validate_map(data))
	{
		err_msg("Invalid map or elements");
		return (0);
	}
	return (1);
}
