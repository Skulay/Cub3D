/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:49:39 by tkhider           #+#    #+#             */
/*   Updated: 2026/06/09 16:49:39 by tkhider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	err_clean(t_game *game, t_arg *arg)
{
	err_msg("Invalid player count");
	clean_exit_game(game, arg);
}

static void	init_map(t_game *game, t_arg *arg)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	game->map.map = arg->map;
	arg->map = NULL;
	game->map.map_height = arg->map_size;
	while (game->map.map[i])
	{
		len = ft_strlen(game->map.map[i]);
		if (len > max)
			max = len;
		i++;
	}
	game->map.map_width = max;
}

static void	handle_player(t_game *game, int i, int j, char c)
{
	game->player.pos_x = j + 0.5;
	game->player.pos_y = i + 0.5;
	set_direction(game, c);
	game->map.map[i][j] = '0';
}

static void	init_player(t_game *game, t_arg *arg)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->map.map[++i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
				|| game->map.map[i][j] == 'W' || game->map.map[i][j] == 'E')
			{
				if (count == 0)
					handle_player(game, i, j, game->map.map[i][j]);
				count++;
			}
			j++;
		}
	}
	if (count != 1)
		err_clean(game, arg);
}

void	init_game(t_game *game, t_arg *arg)
{
	init_colors(game, arg);
	init_map(game, arg);
	init_player(game, arg);
	ft_bzero(&game->key, sizeof(t_key));
}
