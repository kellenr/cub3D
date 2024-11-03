/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:17:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/30 15:08:07 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	display_intro(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->win);

	// mlx_string_put(game->mlx->mlx, game->mlx->win, 400, 300, 0xFFFFFF, "Welcome to the Game!");
	// mlx_string_put(game->mlx->mlx, game->mlx->win, 400, 350, 0xFFFFFF, "Press Enter to continue...");
	mlx_string_put(game->mlx->mlx, game->mlx->win, 400, 300, 0xFFFFFF, \
					"Welcome to Cub3D Game");
	mlx_string_put(game->mlx->mlx, game->mlx->win, 400, 350, 0xFFFFFF, \
					"This project was made by Keramos- and Fibarros.");
	mlx_string_put(game->mlx->mlx, game->mlx->win, 400, 400, 0xFFFFFF, \
					"Press Enter to Start.");
}


void	start_intro(t_game *game)
{
	display_intro(game);
}


// static void	start_screen(t_game *g)
// {
// 	int		h;
// 	int		w;
// 	void	*img;

// 	h = HEIGHT;
// 	w = WIDTH;
// 	img = (g->win->mlx, START, &w, &h);
// 	mlx_put_image_to_window(g->win->mlx, g->win->win, img,
// 		(WIDTH - 1800) / 2, (HEIGHT - 900) / 2);
// 	mlx_destroy_image(g->win->mlx, img);
// 	g->draw = 0;
// }
