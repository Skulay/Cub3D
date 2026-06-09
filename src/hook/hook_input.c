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

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_close(game);
	if (keycode == LEFT)
		game->key.left = 1;
	if (keycode == RIGHT)
		game->key.right = 1;
	if (keycode == W)
		game->key.w = 1;
	if (keycode == A)
		game->key.a = 1;
	if (keycode == S)
		game->key.s = 1;
	if (keycode == D)
		game->key.d = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == LEFT)
		game->key.left = 0;
	if (keycode == RIGHT)
		game->key.right = 0;
	if (keycode == W)
		game->key.w = 0;
	if (keycode == A)
		game->key.a = 0;
	if (keycode == S)
		game->key.s = 0;
	if (keycode == D)
		game->key.d = 0;
	return (0);
}

int	key_handler(t_game *game)
{
	if (game->key.left)
		rotate_left(&game->player);
	if (game->key.right)
		rotate_right(&game->player);
	if (game->key.w)
		move_w(&game->player, &game->map);
	if (game->key.a)
		move_a(&game->player, &game->map);
	if (game->key.s)
		move_s(&game->player, &game->map);
	if (game->key.d)
		move_d(&game->player, &game->map);
	return (0);
}
