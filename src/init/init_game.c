/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:02 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/25 01:55:52 by keramos-         ###   ########.fr       */
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
void	init_txt(t_game *game)
{
	game->txt = malloc(sizeof(t_txt));
	if (!game->txt)
	{
		if (game->mlx)
			free(game->mlx);
		ft_error("Failed to allocate memory for txt");
	}
	game->txt->north = NULL;
	game->txt->south = NULL;
	game->txt->west = NULL;
	game->txt->east = NULL;
	game->txt->sprite = NULL;
	game->txt->floor_color = -1;
	game->txt->ceiling_color = -1;
}

/*
 * Function to initialize the map structure
 * Returns a pointer to t_map on success, exits on failure
 */
void	init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		if (game->txt)
			free(game->txt);
		ft_error("Failed to allocate memory for map");
	}
	game->map->map_data = NULL;
	game->map->width = 0;
	game->map->height = 0;
}

/*
 * Function to initialize the player structure
 * Returns a pointer to t_player on success, exits on failure
 */
void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_error("Failed to allocate memory for player");
	game->player->x = 0.0f;
	game->player->y = 0.0f;
	game->player->dir_x = 0.0f;
	game->player->dir_y = 0.0f;
	game->player->plane_x = 0.0f;
	game->player->plane_y = 0.0f;
	game->player->angle = 0.0f;
	game->player->di = 'N';
}

void	verify_textures(t_game *game)
{
	for (int i = 0; i < TXT_N; i++)
	{
		if (game->txt_data[i] == NULL)
		{
			printf("Texture %d is NULL\n", i);
		}
		else
		{
			printf("Texture %d loaded with first color: 0x%X\n", i, game->txt_data[i][0]);
		}
	}
}

void	load_textures(t_game *game)
{
	game->txt_data = malloc(sizeof(int *) * TXT_COUNT);
	if (!game->txt_data)
		ft_error("Failed to allocate memory for txt_data");
	game->txt_data[NORTH] = ft_xpm(game, game->txt->north);
	game->txt_data[SOUTH] = ft_xpm(game, game->txt->south);
	game->txt_data[WEST] = ft_xpm(game, game->txt->west);
	game->txt_data[EAST] = ft_xpm(game, game->txt->east);
	printf("Load textures\n");
	verify_textures(game);
}
