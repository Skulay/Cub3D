/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 02:19:02 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/28 02:19:02 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_data(t_arg *data)
{
	int	i;

	i = 0;
	ft_putendl_fd(data->no, 1);
	ft_putendl_fd(data->so, 1);
	ft_putendl_fd(data->we, 1);
	ft_putendl_fd(data->ea, 1);
	while (i < 3)
	{
		printf("F -> %i | C -> %i\n", data->f_color[i], data->c_color[i]);
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		ft_putendl_fd(data->map[i], 1);
		i++;
	}
}