/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 07:19:38 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/07 07:19:38 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void print_data(t_arg *data)
{
    ft_putstr_fd(data->NO, 1);
    write(1, "\n", 1);
    ft_putstr_fd(data->SO, 1);
    write(1, "\n", 1);
    ft_putstr_fd(data->WE, 1);
    write(1, "\n", 1);
    ft_putstr_fd(data->EA, 1);
    write(1, "\n", 1);

    int i = 0;
    while (i < 3)
    {
        printf("F -> %i | C -> %i\n", data->f_color[i], data->c_color[i]);
        i++;
    }
}

int	main(int ac, char **av)
{
	t_cube cube;
	// t_arg *data;
	(void)ac;
	(void)av; // pour compil
	// data = init_arg();

	// parsing(av[1], data);
	// print_data(data);
	cube_init(&cube);
	mlx_loop(cube.mlx);
	return (0);
}