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

static int	load_texture(t_mlx *mlx, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		ft_printf("Error\nTexture not found: %s\n", path);
		return (0);
	}
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
	return (1);
}

void	init_textures(t_game *game, t_arg *arg)
{
	if (!load_texture(&game->mlx, &game->tex.north, arg->no))
		clean_exit_game(game);
	if (load_texture(&game->mlx, &game->tex.south, arg->so))
		clean_exit_game(game);
	if (load_texture(&game->mlx, &game->tex.west, arg->we))
		clean_exit_game(game);
	if (load_texture(&game->mlx, &game->tex.east, arg->ea))
		clean_exit_game(game);
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
