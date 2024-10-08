/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:50:19 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 17:13:32 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* destry the imag and the window, and free everytnig after colse the window */
int	close_handler(t_game *game)
{
	if (game->mlx->win)
	{
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
		game->mlx->win = NULL;
	}
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
