/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:17:28 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/25 11:17:28 by alehamad         ###   ########.fr       */
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

void	init_map(t_game *game, t_arg *arg)
{
	int	i;
	int len;
	int max;

	i = 0;
	max = 0;
	game->map.map = arg->map;
	game->map.map_height = arg->map_size;
	while (arg->map[i])
	{
		len = ft_strlen(arg->map[i]);
		if (len > max)
			max = len;
		i++;
	}
	game->map.map_width = max;
}

void	init_player(t_game *game)
{

}

void	init_game(t_game *game, t_arg *arg)
{
	init_colors(game, arg);
	init_map(game, arg);
	init_player(game);
}
