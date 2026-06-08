/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:15:42 by alehamad          #+#    #+#             */
/*   Updated: 2026/06/09 00:29:01 by tkhider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	validate_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i <= 4)
		return (1);
	if (filename[--i] != 'b' || filename[--i] != 'u' || filename[--i] != 'c'
		|| filename[--i] != '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_arg	*data;
	t_game	game;

	if (ac != 2 || validate_extension(av[1]))
		return(err_msg("./cub3D \"/path/map.cub\""), 1);
	ft_bzero(&game, sizeof(t_game));
	if (!pre_parse(av[1]))
		return (1);
	data = init_arg();
	if (!data)
		return (err_msg("Error\n Malloc failed"), 1);
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
