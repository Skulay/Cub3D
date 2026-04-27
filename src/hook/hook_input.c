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
	//ft_render(game);
	return (0);
}