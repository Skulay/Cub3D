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

static void	set_player_dir(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plan_x = 0.66; //c'est le fov ici mdr 120 tu coco
		game->player.plan_y = 0;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plan_x = -0.66;
		game->player.plan_y = 0;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plan_x = 0;
		game->player.plan_y = 0.66;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plan_x = 0;
		game->player.plan_y = -0.66;
	}
}

void	init_player(t_game *game)
{
	int		i;
	int		j;
	char	c;
	int		count;

	i = 0;
	count = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			c = game->map.map[i][j];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				if(count == 0)
				{
					game->player.pos_x = j + 0.5;
					game->player.pos_y = i + 0.5;
					set_direction(game, c);
					game->map.map[i][j] = '0';
				}
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		ft_putstrfd("Error:\nOnly one player is accepted\n")
		clean_exit_game(game);
	}
	ft_putstrfd("Error:\nPlayer not found\n")
	clean_exit_game(game);
}

void	init_game(t_game *game, t_arg *arg)
{
	init_colors(game, arg);
	init_map(game, arg);
	init_player(game);
}
