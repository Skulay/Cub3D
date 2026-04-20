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

int    is_texture(char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        return (1);
    else if (ft_strncmp(line, "SO ", 3) == 0)
        return (1);
    else if (ft_strncmp(line, "WE ", 3) == 0)
        return (1);
    else if (ft_strncmp(line, "EA ", 3) == 0)
        return (1);
    return (0);
}

int    is_colors(char *line)
{
    if (ft_strncmp(line, "F ", 2) == 0)
        return (1);
    else if (ft_strncmp(line, "C ", 2) == 0)
        return (1);
    return (0);
}

int char_map_line(char c)
{
    if (c == '0' || c == '1')
        return (1);
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    if (c == ' ')
        return (1);
    return (0);
}

int    is_map_line(char *line)
{
    int i;
    int len;

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