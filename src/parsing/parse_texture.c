/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:30:08 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/20 07:30:08 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_texture(char *line)
{
	const char	*textures[] = {"NO ", "SO ", "WE ", "EA "};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(line, textures[i], 3) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int is_valid(char *line)
{
	int i;

	i = 3;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || (line[i] != '.' && line[i] != '/'))
		return (0);
	if (line[i] == '.' && line[i + 1] == '/')
		i += 2;
	if (line[i] == '/')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

static int add_texture(char *line, t_arg *data)
{
    char *texture_path;

    if (!line)
        return (0);
    texture_path = &line[3];
    char *dup_texture_path = ft_strdup(texture_path);
    if (!dup_texture_path)
        return (0);
    while (*dup_texture_path == ' ' || *dup_texture_path == '\t')
        dup_texture_path++;
    if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && !data->NO)
        data->NO = dup_texture_path;
    else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && !data->SO)
        data->SO = dup_texture_path;
    else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && !data->WE)
        data->WE = dup_texture_path;
    else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && !data->EA)
        data->EA = dup_texture_path;
    else
    {
        free(dup_texture_path);
        return (0);
    }
    return (1);
}

int	parse_texture(char *line, t_arg *data)
{
	if (!is_texture(line) || !is_valid(line))
		return (0);
	add_texture(line, data);
	return (1);
}