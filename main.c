/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:15:42 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/24 13:15:42 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	print_data(t_arg *data)
{
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	ft_putstr_fd(data->no, 1);
	write(1, "\n", 1);
	ft_putstr_fd(data->so, 1);
	write(1, "\n", 1);
	ft_putstr_fd(data->we, 1);
	write(1, "\n", 1);
	ft_putstr_fd(data->ea, 1);
	write(1, "\n", 1);

	int i = 0;
	while (i < 3)
	{
		printf("F -> %i | C -> %i\n", data->f_color[i], data->c_color[i]);
		i++;
	}

	int j = 0;
	while (data->map[j])
	{
		ft_putstr_fd(data->map[j], 1);
		write(1, "\n", 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	// t_cube cube;
	t_arg *data;
	(void)ac;
	// (void)av; // pour compil

	if (!pre_parse(av[1]))
	{
		return (1);
	}
	data = init_arg();
	if (!parsing(av[1], data))
		return (1);
	print_data(data);
	free_arg(data);
	// cube_init(&cube);
	// mlx_loop(cube.mlx);
	return (0);
}
