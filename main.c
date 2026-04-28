/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:15:42 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/28 02:20:54 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_arg *data;
	t_game game;

	if (ac != 2)
		return (1);
	if (!pre_parse(av[1]))
		return (1);
	data = init_arg();
	if (!parsing(av[1], data))
		return (1);
	print_data(data);
	init_all(&game, data);
	free_arg(data);
	mlx_hook(game.mlx.win, 2, 1L << 0, key_handler, &game);
	// mlx_hook(game.mlx.win, 4, 1L << 2, mouse_handler, game); pris de fractol mais a adapter pour fermer
	mlx_hook(game.mlx.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx.mlx);
	free_game(&game);
	return (0);
}
