/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:42:50 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 02:28:39 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to initialize the images structure
 * Returns a pointer to t_imgs on success, exits on failure
 */
void	init_txt(t_txt *txt)
{
	txt->north = NULL;
	txt->south = NULL;
	txt->west = NULL;
	txt->east = NULL;
	txt->sprite = NULL;
	txt->door = NULL;
	txt->intro = NULL;
	txt->floor_color = -1;
	txt->ceiling_color = -1;
	txt->size = 64;
	txt->step = 0;
	txt->tex_pos = 0;
	txt->x = 0;
	txt->y = 0;
	txt->no.img = NULL;
	txt->so.img = NULL;
	txt->we.img = NULL;
	txt->ea.img = NULL;
	txt->d.img = NULL;
	txt->i.img = NULL;
}

void	load_extra(t_game *game)
{
	game->txt.door = DOOR1;
	init_txt_path(game, &game->txt.d, game->txt.door);
	if (!game->txt.d.img)
		ft_error("Failed to load door texture.");
}

/*
 * Function: load_textures
 * ----------------------
 * Loads all the wall textures for the game
 *
 * game: The game state
 * Returns: 1 on success, 0 on failure
 */
int	load_textures(t_game *game)
{
	init_txt_path(game, &game->txt.no, game->txt.north);
	if (!game->txt.no.img)
		return (0);
	init_txt_path(game, &game->txt.so, game->txt.south);
	if (!game->txt.so.img)
		return (0);
	init_txt_path(game, &game->txt.we, game->txt.west);
	if (!game->txt.we.img)
		return (0);
	init_txt_path(game, &game->txt.ea, game->txt.east);
	if (!game->txt.ea.img)
		return (0);
	if (BONUS)
		load_extra(game);
	return (1);
}
