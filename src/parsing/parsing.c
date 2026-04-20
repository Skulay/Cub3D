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
	if (!line)
		return ;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

int	parsing(char *file, t_arg *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (!is_only_spaces(line))
		{
			remove_nl(line);
			if (is_texture(line))
				parse_texture(line, data);
			else if (is_color(line))
				parse_color(line, data);
			else if (is_map_line(line))
				add_to_map(line, data);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}