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

static int	is_id_valid(char *line, t_check *c)
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

static char	*skip_spaces(char *line)
{
	while (line && (*line == ' ' || (*line >= 9 && *line <= 13)))
		line++;
	return (line);
}

static int	is_not_empty_line(char *line)
{
	char	*str;

	str = skip_spaces(line);
	if (*str == '\0' || *str == '\n')
		return (0);
	return (1);
}

static int check_id(t_check *c)
{
	if (c->no == 1 && c->so == 1 && c->we == 1 
		&& c->ea == 1 && c->f == 1 && c->c == 1)
		return (1);
	return (0);
}

static int	check_map_line(char *line)
{
	char	*str;

	str = skip_spaces(line);
	if (*str == '1' || *str == '0')
		return (1);
	return (0);
}

static int	check_cub_file(int fd, t_check *c)
{
	char	*line;
	int		map_started;

	map_started = 0;
	while ((line = get_next_line(fd)))
	{
		if (is_not_empty_line(line))
		{
			if (!check_id(c))
			{
				if (is_map_line(line))
				{
					free(line);
					return (0);
				}
				if (!is_id_valid(skip_spaces(line), c))
				{
					free(line);
					return (0);
				}
			}
			else if (!map_started)
			{
				if (check_map_line(line))
					map_started = 1;
				else
				{
					free(line);
					return (0);
				}
			}
		}
		free(line);
	}
	return (check_id(c) && map_started);
}

int	pre_parse(char *file)
{
	int		fd;
	t_check	c;

	init_check(&c);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	if (!check_cub_file(fd, &c))
	{
		close(fd);
		err_cub_format();
		return (0);
	}
	ft_putstr_fd("SUCCES PRE PARSE\n", 1);
	close(fd);
	return (1);
}
