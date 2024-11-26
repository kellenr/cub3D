/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:17:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/24 18:27:13 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	display_intro(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);

	mlx_string_put(game->mlx, game->win, 400, 300, 0xFFFFFF, \
					"Welcome to Cub3D Game");
	mlx_string_put(game->mlx, game->win, 400, 350, 0xFFFFFF, \
					"This project was made by Keramos- and Fibarros.");
	mlx_string_put(game->mlx, game->win, 400, 400, 0xFFFFFF, \
					"Press Enter to Start.");
}


void	start_intro(t_game *game)
{
	display_intro(game);
}


// void	load_intro(t_game *game, t_paths *paths)
// {

// }
