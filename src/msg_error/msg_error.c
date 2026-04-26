/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:45:28 by alehamad          #+#    #+#             */
/*   Updated: 2026/04/22 17:45:28 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	err_cub_format(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid .cub file structure. Rules:\n", 2);
	ft_putstr_fd("- 6 identifiers required: NO, SO, WE, EA, F, C\n", 2);
	ft_putstr_fd("- Order of identifiers: Any\n", 2);
	ft_putstr_fd("- Duplicates: Not allowed\n", 2);
	ft_putstr_fd("- Map: Must be the very last element\n", 2);
}

void	err_msg(char *msg)
{
	ft_putendl_fd("Error:", 2);
	ft_putendl_fd(msg, 2);
}