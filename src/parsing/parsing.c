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

int parsing(char *file)
{
    int fd;
    char *line;

    fd = open("map.cub", O_RDONLY);
    line = get_next_line(fd)
    if (!line)
        return (1);
    while (line)
    {
        if (is_texture(line))
            parse_texture(line); 
        else if (is_color(line))
            parse_color(line);
        else if (is_map_line(line))
            add_to_map(line);
        line = get_next_line(fd)
        if (!line)
            return (1)
    }
    return (0);
}