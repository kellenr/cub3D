/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:02 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/03 15:09:08 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		ft_error("Failed to allocate memory for mlx");

}

t_txt	*init_txt(t_game *game)
{
	t_txt	*txt;

	txt = malloc(sizeof(t_txt));
	if (!txt)
	{
		free(game);
		ft_error("Failed to allocate memory for txt");
	}
	txt->north = NULL;
	txt->south = NULL;
	txt->west = NULL;
	txt->east = NULL;
	txt->floor_color = -1;
	txt->ceiling_color = -1;
	return (txt);
}

t_map	*init_map(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		free(game->mlx);
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
	player->direction = 'N'; // Default direction
	return (player);
}
