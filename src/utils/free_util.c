/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhider <tkhider@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:46:06 by alehamad          #+#    #+#             */
/*   Updated: 2026/05/02 01:41:26 by tkhider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	clean_exit_game(t_game *game, t_arg *data)
{
	if (data)
		free_arg(data);
	free_game(game);
	exit(1);
}

void	free_close(char *line, int fd)
{
	err_msg("invalid map (empty line)");
	if (line != NULL)
		free(line);
	close(fd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_arg(t_arg *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
		free_tab(data->map);
	free(data);
}
