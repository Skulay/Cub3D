/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:17:57 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/19 15:17:57 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_arg
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	**map;
	int		f_color[3];
	int		c_color[3];
	int		f_defined;
	int		c_defined;

}        t_arg;

//parsing
int	parsing(char *file, t_arg *data);
int	is_texture(char *line);
int	is_color(char *line);
int	parse_texture(char *line, t_arg *data);
int	parse_color(char *line, t_arg *data);

//init
t_arg	*init_arg(void);




#endif