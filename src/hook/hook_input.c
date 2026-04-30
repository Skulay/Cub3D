/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:57:13 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/27 17:57:13 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_close(game);
	if (keycode == LEFT)
		rotate_left(&game->player);
	if (keycode == RIGHT)
		rotate_right(&game->player);
	if (keycode == W)
		move_w(&game->player, &game->map);
	if (keycode == A)
		move_a(&game->player, &game->map);
	if (keycode == S)
		move_s(&game->player, &game->map);
	if (keycode == D)
		move_d(&game->player, &game->map);
	render_frame(game);
	return (0);
}