/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 01:18:16 by alehamad          #+#    #+#             */
/*   Updated: 2026/05/04 01:18:16 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_ray(t_game *g, int x, int width)
{
	g->ray.camera_x = 2 * x / (double)width - 1;
	g->ray.raydir_x = g->player.dir_x + g->player.plan_x * g->ray.camera_x;
	g->ray.raydir_y = g->player.dir_y + g->player.plan_y * g->ray.camera_x;
	g->ray.map_x = (int)g->player.pos_x;
	g->ray.map_y = (int)g->player.pos_y;
	g->ray.deltadist_x = fabs(1 / g->ray.raydir_x);
	g->ray.deltadist_y = fabs(1 / g->ray.raydir_y);
	g->ray.hit = 0;
}

static void	init_step(t_game *g)
{
	if (g->ray.raydir_x < 0)
	{
		g->ray.step_x = -1;
		g->ray.sidedist_x = (g->player.pos_x - g->ray.map_x)
			* g->ray.deltadist_x;
	}
	else
	{
		g->ray.step_x = 1;
		g->ray.sidedist_x = (g->ray.map_x + 1.0 - g->player.pos_x)
			* g->ray.deltadist_x;
	}
	if (g->ray.raydir_y < 0)
	{
		g->ray.step_y = -1;
		g->ray.sidedist_y = (g->player.pos_y - g->ray.map_y)
			* g->ray.deltadist_y;
	}
	else
	{
		g->ray.step_y = 1;
		g->ray.sidedist_y = (g->ray.map_y + 1.0 - g->player.pos_y)
			* g->ray.deltadist_y;
	}
}

static void	dda(t_game *g)
{
	while (g->ray.hit == 0)
	{
		if (g->ray.sidedist_x < g->ray.sidedist_y)
		{
			g->ray.sidedist_x += g->ray.deltadist_x;
			g->ray.map_x += g->ray.step_x;
			g->ray.side = 0;
		}
		else
		{
			g->ray.sidedist_y += g->ray.deltadist_y;
			g->ray.map_y += g->ray.step_y;
			g->ray.side = 1;
		}
		if (g->ray.map_x < 0 || g->ray.map_x >= g->map.map_width
			|| g->ray.map_y < 0 || g->ray.map_y >= g->map.map_height)
			break ;
		if (g->map.map[g->ray.map_y][g->ray.map_x] == '1')
			g->ray.hit = 1;
	}
}

int	raycast(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(g, x, WIDTH);
		init_step(g);
		dda(g);
		calc_wall(g);
		draw_column(g, x);
		x++;
	}
	return (0);
}
