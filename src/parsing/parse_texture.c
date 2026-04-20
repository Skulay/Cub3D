/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:30:08 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/20 07:30:08 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

int parse_texture(line);