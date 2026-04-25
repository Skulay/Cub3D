/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:35:08 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/25 11:35:08 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_textures(game, arg)
{
	
}

void	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		clean_exit_game(game);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "CUB3D");
	if (!game->mlx.win)
		clean_exit_game(game);
}

void	init_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	if (!game->img.img)
		clean_exit_game(game);
	game->img.addr = mlx_get_data_addr(
		game->img.img,
		&game->img.bpp,
		&game->img.line_len,
		&game->img.endian
	);
	if (!game->img.addr)
		clean_exit_game(game);
}

void	init_all(t_game *game, t_arg *arg)
{
	init_mlx(game);
	init_img(game);
	init_game(game, arg);
	init_textures(game, arg);
}
