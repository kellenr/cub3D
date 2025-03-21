/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:17:40 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 02:27:18 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: display_intro
 * ----------------------
 * Displays the intro screen with game information and controls
 *
 * game: The game state
 */
void	display_intro(t_game *game)
{
	int		width;
	int		height;

	width = 1800;
	height = 960;
	game->txt.i.img = mlx_xpm_file_to_image(game->mlx, INTRO1, &width, &height);
	if (!game->txt.i.img)
	{
		free_mlx(game);
		clean_error(game, "Failed to load texture");
	}
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->txt.i.img, \
				(W_WIDTH - width) / 2, (W_HEIGHT - height) / 2);
	mlx_destroy_image(game->mlx, game->txt.i.img);
	game->txt.i.img = NULL;
}

/*
 * Function: start_intro
 * --------------------
 * Initializes and starts displaying the intro screen
 *
 * game: The game state
 */
void	start_intro(t_game *game)
{
	game->intro_active = 1;
	display_intro(game);
}
