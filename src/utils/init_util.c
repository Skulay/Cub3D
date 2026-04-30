/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:54:29 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/30 13:54:29 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	rgb_to_int(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	init_colors(t_game *game, t_arg *arg)
{
	game->floor_color = rgb_to_int(arg->f_color);
	game->ceiling_color = rgb_to_int(arg->c_color);
}
