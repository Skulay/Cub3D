/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:15:42 by alehamad          #+#    #+#             */
/*   Updated: 2026/05/04 16:53:28 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_arg	*data;
	t_game	game;

	if (ac != 2)
	{
		err_msg("./cub3D \"/path/map.cub\"");
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	if (!pre_parse(av[1]))
		return (1);
	data = init_arg();
	if (!parsing(av[1], data))
	{
		free_arg(data);
		return (1);
	}
	init_all(&game, data);
	free_arg(data);
	mlx_hook(game.mlx.win, 2, 1L << 0, key_handler, &game);
	mlx_hook(game.mlx.win, 17, 0, handle_close, &game);
	mlx_loop_hook(game.mlx.mlx, render_frame, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
