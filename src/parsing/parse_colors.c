/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:30:34 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/20 07:30:34 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int    is_colors(char *line)
{
    if (ft_strncmp(line, "F ", 2) == 0)
        return (1);
    else if (ft_strncmp(line, "C ", 2) == 0)
        return (1);
    return (0);
}

int parse_color(line);