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

struct s_arg
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char **map;

    int f_color[3];
    int c_color[3];
    int f_defined;
    int c_defined;

}        t_arg;

struct s_player
{
    int x;
    int y;
};






#endif