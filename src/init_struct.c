/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:13:55 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/20 07:13:55 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_arg	*init_arg(void)
{
	t_arg   *data;

	data = malloc(sizeof(t_arg));
	if (!data)
		return (NULL);
	data->NO = NULL;
	data->SO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	ft_memset(data->f_color, 0, sizeof(int) * 3);
	ft_memset(data->c_color, 0, sizeof(int) * 3);
	data->f_defined = 0;
	data->c_defined = 0;
	data->map_size = 0;
	data->map = malloc(MAX_MAP_SIZE * sizeof(char *));
	if (!data->map)
	{
		free(data);
		return (NULL);
	}
	return (data);
}
