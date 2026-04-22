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

static void remove_nl(char *line)
{
    int i = 0;
    if (!line || line[0] == '\0')
        return;

    while (line[i])
    {
        if (line[i] == '\n' || line[i] == '\r' || line[i] < 32)
            line[i] = '\0';
        i++;
    }
}

// static int all_set(t_arg *data)
// {
//     return (data->NO && data->SO && data->WE && data->EA &&
//             data->map && data->f_defined && data->c_defined);
// }

static void parsing_helper(char *line, t_arg *data)
{
	printf("Ligne lue: %s\n", line);
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

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		remove_nl(line);
		if (!is_only_spaces(line))
			parsing_helper(line, data);
		free(line);
		line = get_next_line(fd);
	}
	// if (!all_set(data))
	// {
	// 	close(fd);
	// 	return (1);
	// }
	close(fd);
	return (0);
}
