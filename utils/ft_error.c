/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:17:18 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 08:40:38 by kellen           ###   ########.fr       */
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

void	clean_error(t_game *game, char *msg)
{
	if (game->n_line)
	{
		free(game->n_line);
		game->n_line = NULL;
	}
	if (game->fd > 0)
	{
		close(game->fd);
		game->fd = -1;
	}
	ft_putstr_fd(P_R"Error\n"RT, 2);
	ft_putstr_fd("😅 Oops! ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_game(game);
	get_next_line(-1);
	exit(EXIT_FAILURE);
}
