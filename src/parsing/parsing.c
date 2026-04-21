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
    int	i;

	i = 0;
    if (!line || line[0] == '\0')
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

// int all_set(t_arg *data)
// {
// 	if (data->NO == NULL)
// 		return (0);
// 	if (data->SO == NULL)
// 		return (0);
// 	if (data->WE == NULL)
// 		return (0);
// 	if (data->EA == NULL)
// 		return (0);
// 	if (data->map == NULL)
// 		return (0);
// 	if (data->f_defined == 0)
// 		return (0);
// 	if (data->c_defined == 0)
// 		return (0);
// 	return (1);
// }

int all_set(t_arg *data)
{
    return (data->NO && data->SO && data->WE && data->EA &&
            data->map && data->f_defined && data->c_defined);
}

int	parsing(char *file, t_arg *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
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
	if (!all_set(data))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}