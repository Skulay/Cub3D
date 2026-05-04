/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 01:20:43 by alehamad          #+#    #+#             */
/*   Updated: 2026/05/04 01:20:43 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	calc_wall(t_game *g)
{
	if (g->ray.side == 0)
		g->ray.perpwalldist = (g->ray.map_x - g->player.pos_x
				+ (1 - g->ray.step_x) / 2) / g->ray.raydir_x;
	else
		g->ray.perpwalldist = (g->ray.map_y - g->player.pos_y
				+ (1 - g->ray.step_y) / 2) / g->ray.raydir_y;
	g->ray.line_height = (int)(HEIGHT / g->ray.perpwalldist);
	g->ray.draw_start = -g->ray.line_height / 2 + HEIGHT / 2;
	if (g->ray.draw_start < 0)
		g->ray.draw_start = 0;
	g->ray.draw_end = g->ray.line_height / 2 + HEIGHT / 2;
	if (g->ray.draw_end >= HEIGHT)
		g->ray.draw_end = HEIGHT - 1;
}

static t_texture	*get_tex(t_game *g)
{
	if (g->ray.side == 0)
	{
		if (g->ray.raydir_x > 0)
			return (&g->tex.west);
		return (&g->tex.east);
	}
	if (g->ray.raydir_y > 0)
		return (&g->tex.north);
	return (&g->tex.south);
}

static int	get_tex_x(t_game *g, t_texture *tex)
{
	double	wall_x;
	int		tex_x;

	if (g->ray.side == 0)
		wall_x = g->player.pos_y + g->ray.perpwalldist * g->ray.raydir_y;
	else
		wall_x = g->player.pos_x + g->ray.perpwalldist * g->ray.raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((g->ray.side == 0 && g->ray.raydir_x > 0)
		|| (g->ray.side == 1 && g->ray.raydir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	draw_column(t_game *g, int x)
{
	int			y;
	t_texture	*tex;
	int			tex_x;
	double		t_pos;

	y = -1;
	tex = get_tex(g);
	tex_x = get_tex_x(g, tex);
	t_pos = (g->ray.draw_start - HEIGHT / 2 + g->ray.line_height / 2)
		* ((double)tex->height / g->ray.line_height);
	while (++y < HEIGHT)
	{
		if (y < g->ray.draw_start)
			put_pixel(&g->img, x, y, g->ceiling_color);
		else if (y > g->ray.draw_end)
			put_pixel(&g->img, x, y, g->floor_color);
		else
		{
			put_pixel(&g->img, x, y, *(int *)(tex->addr + ((int)t_pos
						* tex->line_len + tex_x * (tex->bpp / 8))));
			t_pos += (double)tex->height / g->ray.line_height;
		}
	}
}
