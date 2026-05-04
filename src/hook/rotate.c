/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 02:34:17 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/29 02:34:17 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_left(t_player *p)
{
	double	old_dir_x;
	double	old_plan_x;
	double	rot;

	rot = -0.05;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot) - p->dir_y * sin(rot);
	p->dir_y = old_dir_x * sin(rot) + p->dir_y * cos(rot);
	old_plan_x = p->plan_x;
	p->plan_x = p->plan_x * cos(rot) - p->plan_y * sin(rot);
	p->plan_y = old_plan_x * sin(rot) + p->plan_y * cos(rot);
}

void	rotate_right(t_player *p)
{
	double	old_dir_x;
	double	old_plan_x;
	double	rot;

	rot = 0.05;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot) - p->dir_y * sin(rot);
	p->dir_y = old_dir_x * sin(rot) + p->dir_y * cos(rot);
	old_plan_x = p->plan_x;
	p->plan_x = p->plan_x * cos(rot) - p->plan_y * sin(rot);
	p->plan_y = old_plan_x * sin(rot) + p->plan_y * cos(rot);
}
