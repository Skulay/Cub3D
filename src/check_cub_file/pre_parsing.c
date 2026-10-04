/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:20:18 by alehamad          #+#    #+#             */
/*   Updated: 2026/07/28 14:11:55 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	finish_file(int fd, char *line)
{
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	check_cub_file(int fd, t_check *c)
{
	char	*line;
	int		map_started;

	map_started = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_not_empty_line(line))
		{
			if (!check_id(c))
			{
				if (check_map_line(line) || !is_id_valid(skip_spaces(line), c))
					return (finish_file(fd, line), 0);
			}
			else if (!map_started && check_map_line(line))
				map_started = 1;
			else if (!map_started)
				return (finish_file(fd, line), 0);
		}
		free(line);
	}
	return (check_id(c) && map_started);
}

int	pre_parse(char *file)
{
	int		fd;
	t_check	c;

	init_check(&c);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nopening file");
		return (0);
	}
	if (!check_cub_file(fd, &c))
	{
		close(fd);
		err_cub_format();
		return (0);
	}
	close(fd);
	return (1);
}
