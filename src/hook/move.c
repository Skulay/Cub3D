/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:28:10 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/30 13:28:10 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_w(t_player *p, t_map *map)
{
	double new_x = p->pos_x + p->dir_x * MOVE_SPEED;
	double new_y = p->pos_y + p->dir_y * MOVE_SPEED;

	if (map->map[(int)p->pos_y][(int)new_x] == '0')
		p->pos_x = new_x;
	if (map->map[(int)new_y][(int)p->pos_x] == '0')
		p->pos_y = new_y;
}

void	move_s(t_player *p, t_map *map)
{
	double new_x = p->pos_x - p->dir_x * MOVE_SPEED;
	double new_y = p->pos_y - p->dir_y * MOVE_SPEED;

	if (map->map[(int)p->pos_y][(int)new_x] == '0')
		p->pos_x = new_x;
	if (map->map[(int)new_y][(int)p->pos_x] == '0')
		p->pos_y = new_y;
}

void	move_a(t_player *p, t_map *map)
{
	double new_x = p->pos_x + p->dir_y * MOVE_SPEED;
	double new_y = p->pos_y - p->dir_x * MOVE_SPEED;

	if (map->map[(int)p->pos_y][(int)new_x] == '0')
		p->pos_x = new_x;
	if (map->map[(int)new_y][(int)p->pos_x] == '0')
		p->pos_y = new_y;
}

void	move_d(t_player *p, t_map *map)
{
	double new_x = p->pos_x - p->dir_y * MOVE_SPEED;
	double new_y = p->pos_y + p->dir_x * MOVE_SPEED;

	if (map->map[(int)p->pos_y][(int)new_x] == '0')
		p->pos_x = new_x;
	if (map->map[(int)new_y][(int)p->pos_x] == '0')
		p->pos_y = new_y;
}
