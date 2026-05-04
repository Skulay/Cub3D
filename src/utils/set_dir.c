/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:55:17 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/30 13:55:17 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_n(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->player.plan_x = 0.66;
	game->player.plan_y = 0;
}

static void	set_s(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->player.plan_x = -0.66;
	game->player.plan_y = 0;
}

static void	set_e(t_game *game)
{
	game->player.dir_x = 1;
	game->player.dir_y = 0;
	game->player.plan_x = 0;
	game->player.plan_y = 0.66;
}

static void	set_w(t_game *game)
{
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plan_x = 0;
	game->player.plan_y = -0.66;
}

void	set_direction(t_game *game, char c)
{
	if (c == 'N')
		set_n(game);
	else if (c == 'S')
		set_s(game);
	else if (c == 'E')
		set_e(game);
	else if (c == 'W')
		set_w(game);
}
