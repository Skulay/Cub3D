/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:51:05 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/24 18:51:05 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_ray(t_game *g, int x, int width)
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

void	init_step(t_game *g)
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

void	dda(t_game *g)
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

void	draw_column(t_game *g, int x)
{
	int			y;
	t_texture	*tex;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			color;

	y = 0;
	if (g->ray.side == 0)
	{
		if (g->ray.raydir_x > 0)
			tex = &g->tex.west;
		else
			tex = &g->tex.east;
	}
	else
	{
		if (g->ray.raydir_y > 0)
			tex = &g->tex.north;
		else
			tex = &g->tex.south;
	}
	if (g->ray.side == 0)
		wall_x = g->player.pos_y + g->ray.perpwalldist * g->ray.raydir_y;
	else
		wall_x = g->player.pos_x + g->ray.perpwalldist * g->ray.raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((g->ray.side == 0 && g->ray.raydir_x > 0)
		|| (g->ray.side == 1 && g->ray.raydir_y < 0))
		tex_x = tex->width - tex_x - 1;
	step = (double)tex->height / g->ray.line_height;
	tex_pos = (g->ray.draw_start - HEIGHT / 2 + g->ray.line_height / 2) * step;
	while (y < HEIGHT)
	{
		if (y < g->ray.draw_start)
			put_pixel(&g->img, x, y, g->ceiling_color);
		else if (y > g->ray.draw_end)
			put_pixel(&g->img, x, y, g->floor_color);
		else
		{
			tex_y = (int)tex_pos;
			tex_pos += step;
			color = *(int *)(tex->addr
				+ (tex_y * tex->line_len
				+ tex_x * (tex->bpp / 8)));
			put_pixel(&g->img, x, y, color);
		}
		y++;
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

int	render_frame(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(
		game->mlx.mlx,
		game->mlx.win,
		game->img.img,
		0, 0
		);
	return (0);
}
