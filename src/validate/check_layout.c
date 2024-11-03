/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:33:03 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/30 16:08:44 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: validate_map
 * ----------------------
 * Validates the map by checking if it is enclosed by walls and contains only allowed characters.
 *
 * game: Pointer to the game structure.
 *
 * returns: 1 if the map is valid, 0 otherwise.
 */
/* int	validate_map(t_game *game)
{
	if (!is_map_enclosed(game->map))
	{
		free_map(game->map);
		free_game(game);
		ft_error("The map is not enclosed by walls!");
	}
	if (!validate_map_chars(game->map))
	{
		free_map(game->map);
		free_game(game);
		ft_error("Invalid characters in map!");
	}
	if (!is_map_valid_layout(game->map))
	{
		free_map(game->map);
		free_game(game);
		ft_error("Invalid map layout!");

	}
	return (1);
} */

