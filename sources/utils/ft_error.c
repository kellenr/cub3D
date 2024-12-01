/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:17:18 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/22 20:52:45 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to print an error message and exit the program.
 * str: The error message to print.
 */
void	ft_error(char *str)
{
	ft_putstr_fd(P_R"Error\n"RT, 2);
	ft_putstr_fd("😅 Oops! ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
