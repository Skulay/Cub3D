/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:00:50 by alehamad          #+#    #+#             */
/*   Updated: 2026/06/02 06:16:15 by tkhider          ###   ########.fr       */
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

static int	handle_line(char *line, t_arg *data, int *map_status)
{
	if (is_only_spaces(line) != 0)
	{
		if (*map_status == 1)
			*map_status = 2;
		return (1);
	}
	if (*map_status == 2)
		return (0);
	if (*map_status == 0)
	{
		if (is_map_line(line) != 0)
			*map_status = 1;
		else
		{
			parsing_helper(line, data);
			return (1);
		}
	}
	if (is_map_line(line) == 0)
		return (0);
	return (add_to_map(line, data));
}

static void	purge_gnl_buffer(int fd, char *current_line)
{
	if (!current_line)
		return ;
	while (NULL != current_line)
	{
		free(current_line);
		current_line = get_next_line(fd);
	}
}

int	parsing(char *file, t_arg *data)
{
	int		fd;
	char	*line;
	int		map_status;

	map_status = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_nl(line);
		if (handle_line(line, data, &map_status) == 0)
		{
			purge_gnl_buffer(fd, line);
			return (close(fd), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (all_set(data) == 0 || validate_map(data) == 0)
	{
		err_msg("Invalid map or elements");
		return (0);
	}
	return (1);
}
