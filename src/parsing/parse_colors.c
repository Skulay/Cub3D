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

int	is_color(char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (1);	
	return (0);
}

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
	if (rgb[0] == -1 || line[*i] != ',')
		return (0);
	(*i)++;
	rgb[1] = get_nbr(line, i);
	if (rgb[1] == -1 || line[*i] != ',')
		return (0);
	(*i)++;
	rgb[2] = get_nbr(line, i);
	if (rgb[2] == -1)
		return (0);
	if (line[*i] != '\0')
		return (0);
	return (1);
}

int	parse_color(char *line, t_arg *data)
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
	if (line[0] == 'F' && data->f_defined == 0)
	{
		ft_memcpy(data->f_color, rgb, sizeof(int) * 3);
		data->f_defined = 1;
	}
	else if (line[0] == 'C' && data->c_defined == 0)
	{
		ft_memcpy(data->c_color, rgb, sizeof(int) * 3);
		data->c_defined = 1;
	}
	return (1);
}
