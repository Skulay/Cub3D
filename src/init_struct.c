/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 07:13:55 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/20 07:13:55 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_arg   *init_arg(void)
{
    t_arg   data;

    data = malloc(sizeof(t_arg));
    if (!data)
        return (NULL);
    data->NO = NULL;
    data->SO = NULL;
    data->WE = NULL;
    data->EA = NULL;
    data->F = NULL;
    data->C = NULL;
    data->map = NULL;
    return (data);
}
