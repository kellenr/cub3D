/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:12:31 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 09:10:42 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: start_game
 * -------------------
 * The main game loop function called on each frame
 *
 * game: The game state
 * Returns: Always returns 0
 */
int	start_game(t_game *game)
{
	if (game->intro_active)
	{
		display_intro(game);
		return (0);
	}
	handle_movement(game);
	render_frame(game);
	return (0);
}

/*
 * Function: init_game_loop
 * -----------------------
 * Sets up the game loop
 *
 * game: The game state
 */
void	init_game_loop(t_game *game)
{
	game->intro_active = 1;
	game->mini_active = 0;
	game->mini_scoop = 0;
	if (!load_textures(game))
	{
		free_mlx(game);
		clean_error(game, "Failed to load textures");
	}
	mlx_loop_hook(game->mlx, &start_game, game);
}
