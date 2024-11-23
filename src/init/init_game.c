/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:02 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/23 02:08:00 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to initialize the game structure
 * Initializes the pointers to NULL
 * game: Pointer to the game structure
 * Returns nothing
 */
void	initialize_game(t_game *game)
{
	if (!game)
		return;
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->imgs = NULL;
	game->player = NULL;
	game->txt = NULL;
	game->ray = NULL;
	game->intro_active = 1; // Example default value
}

/*
 * Function to initialize the images structure
 * Returns a pointer to t_imgs on success, exits on failure
 */
t_txt	*init_txt(t_game *game)
{
	t_txt	*txt;

	txt = malloc(sizeof(t_txt));
	if (!txt)
	{
		if (game->mlx)
			free(game->mlx);
		ft_error("Failed to allocate memory for txt");
	}
	txt->north = NULL;
	txt->south = NULL;
	txt->west = NULL;
	txt->east = NULL;
	txt->sprite = NULL;
	txt->floor_color = -1;
	txt->ceiling_color = -1;
	return (txt);
}

/*
 * Function to initialize the map structure
 * Returns a pointer to t_map on success, exits on failure
 */
t_map	*init_map(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		if (game->txt)
			free(game->txt);
		ft_error("Failed to allocate memory for map");
	}
	map->map_data = NULL;
	map->width = 0;
	map->height = 0;
	return (map);
}

/*
 * Function to initialize the player structure
 * Returns a pointer to t_player on success, exits on failure
 */
t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		ft_error("Failed to allocate memory for player");
	player->x = 0.0f;
	player->y = 0.0f;
	player->dir_x = 0.0f;
	player->dir_y = 0.0f;
	player->plane_x = 0.0f;
	player->plane_y = 0.0f;
	player->angle = 0.0f;
	player->di = 'N';
	return (player);
}


void	init_textures(t_game *game)
{
	game->txt_data = malloc(sizeof(int *) * 5);
	if (!game->txt_data)
		ft_error("Failed to allocate memory for txt_data");
	game->txt_data[NORTH] = ft_xpm(game, game->txt->north);
	game->txt_data[SOUTH] = ft_xpm(game, game->txt->south);
	game->txt_data[WEST] = ft_xpm(game, game->txt->west);
	game->txt_data[EAST] = ft_xpm(game, game->txt->east);
	game->txt_data[SPRITE] = ft_xpm(game, game->txt->sprite);
}
