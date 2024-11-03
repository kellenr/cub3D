/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:02 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/26 00:46:35 by keramos-         ###   ########.fr       */
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
