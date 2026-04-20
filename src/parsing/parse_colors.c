/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:30:34 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/20 07:30:34 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	get_nbr(char *str, int *i)
{
	int	nb;
	int	len;

	nb = 0;
	len = 0;
	if (!ft_isdigit(str[*i]))
		return (-1);
	while (str[*i] && ft_isdigit(str[*i]) && len < 3)
	{
		nb = nb * 10 + (str[*i] - '0');
		(*i)++;
		len++;
	}
	if (nb > 255)
		return (-1);
	return (nb);
}

static int	add_rgb(char *line, int *i, int *rgb)
{
	rgb[0] = get_nbr(line, i);
	if (rgb[0] == -1 || line[(*i)++] != ',')
		return (0);
	rgb[1] = get_nbr(line, i);
	if (rgb[1] == -1 || line[(*i)++] != ',')
		return (0);
	rgb[2] = get_nbr(line, i);
	if (rgb[2] == -1)
		return (0);
	if (line[*i] != '\0')
		return (0);
	return (1);
}

int	parse_color(char *line, t_data *data)
{
	int	i;
	int	rgb[3];

	if (!line)
		return (0);
	if (line[0] == 'F' && line[1] == ' ')
		i = 2;
	else if (line[0] == 'C' && line[1] == ' ')
		i = 2;
	else
		return (0);
	if (!add_rgb(line, &i, rgb))
		return (0);
	if (line[0] == 'F')
		ft_memcpy(data->f_color, rgb, sizeof(int) * 3);
	else
		ft_memcpy(data->c_color, rgb, sizeof(int) * 3);
	return (1);
}

F 123,123,123