/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:05:34 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/27 15:05:34 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	free_map(t_map *map)
{
	if (map)
		free_tab(map->map);
}

static void	free_mlx(t_img *img, t_mlx *mlx)
{
	if (!img || !mlx)
		return ;
	if (img->img)
		mlx_destroy_image(mlx->mlx, img->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

static void	free_tex(t_tex *tex, t_mlx *mlx)
{
	if (!tex || !mlx)
		return ;
	if (tex->north.img)
		mlx_destroy_image(mlx->mlx, tex->north.img);
	if (tex->south.img)
		mlx_destroy_image(mlx->mlx, tex->south.img);
	if (tex->west.img)
		mlx_destroy_image(mlx->mlx, tex->west.img);
	if (tex->east.img)
		mlx_destroy_image(mlx->mlx, tex->east.img);
}

void	free_game(t_game *game)
{
	free_tex(&game->tex, &game->mlx);
	free_mlx(&game->img, &game->mlx);
	free_map(&game->map);
}

int	handle_close(t_game *game)
{
	free_game(game);
	exit(0);
}
