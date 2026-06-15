/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 22:46:21 by tkhider           #+#    #+#             */
/*   Updated: 2026/06/15 22:46:21 by tkhider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_check(t_check *c)
{
	c->no = 0;
	c->so = 0;
	c->we = 0;
	c->ea = 0;
	c->f = 0;
	c->c = 0;
}

void	init_color(int *tab)
{
	tab[0] = -1;
	tab[1] = -1;
	tab[2] = -1;
}

t_arg	*init_arg(void)
{
	t_arg	*data;

	data = malloc(sizeof(t_arg));
	if (!data)
		return (NULL);
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	init_color(data->f_color);
	init_color(data->c_color);
	data->f_defined = 0;
	data->c_defined = 0;
	data->map_size = 0;
	data->map = ft_calloc(MAX_MAP_SIZE, sizeof(char *));
	if (!data->map)
	{
		free(data);
		return (NULL);
	}
	return (data);
}
