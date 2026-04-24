/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:53:42 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/22 16:53:42 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_id_valid(char *line, t_check *c)
{
	if (!ft_strncmp(line, "NO ", 3) && ++(c->no))
		return (c->no == 1);
	if (!ft_strncmp(line, "SO ", 3) && ++(c->so))
		return (c->so == 1);
	if (!ft_strncmp(line, "WE ", 3) && ++(c->we))
		return (c->we == 1);
	if (!ft_strncmp(line, "EA ", 3) && ++(c->ea))
		return (c->ea == 1);
	if (!ft_strncmp(line, "F ", 2) && ++(c->f))
		return (c->f == 1);
	if (!ft_strncmp(line, "C ", 2) && ++(c->c))
		return (c->c == 1);
	return (0);
}

char	*skip_spaces(char *line)
{
	while (line && (*line == ' ' || (*line >= 9 && *line <= 13)))
		line++;
	return (line);
}

int	is_not_empty_line(char *line)
{
	char	*str;

	str = skip_spaces(line);
	if (*str == '\0' || *str == '\n')
		return (0);
	return (1);
}

int	check_id(t_check *c)
{
	if (c->no == 1 && c->so == 1 && c->we == 1
		&& c->ea == 1 && c->f == 1 && c->c == 1)
		return (1);
	return (0);
}

int	check_map_line(char *line)
{
	char	*str;

	str = skip_spaces(line);
	if (*str == '1' || *str == '0')
		return (1);
	return (0);
}
