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
	render_frame(game);
	return (0);
}