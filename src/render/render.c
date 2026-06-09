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

int	game_loop(t_game *game)
{
	key_handler(game);
	render_frame(game);
	return (0);
}
