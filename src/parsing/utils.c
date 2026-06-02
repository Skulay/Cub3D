/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:45:55 by alehamad          #+#    #+#             */
/*   Updated: 2026/06/02 06:02:37 by tkhider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_only_spaces(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	remove_nl(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0')
		return ;
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\r')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
}

int	all_set(t_arg *data)
{
	return (data->no && data->so && data->we && data->ea && data->map
		&& data->f_defined && data->c_defined);
}
