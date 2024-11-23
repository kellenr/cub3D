/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:26:57 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/22 22:23:07 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->map_data)
	{
		while (map->map_data[i])
		{
			free(map->map_data[i]);
			map->map_data[i] = NULL;
			i++;
		}
		free(map->map_data);
		map->map_data = NULL;
	}
	free(map);
}

void	free_texture(t_txt *txt)
{
	if (txt)
	{
		if (txt->north)
			free(txt->north);
		if (txt->south)
			free(txt->south);
		if (txt->west)
			free(txt->west);
		if (txt->east)
			free(txt->east);
		if (txt->sprite)
			free(txt->sprite);
		free(txt);
	}
}

void	free_player(t_player *player)
{
	if (player)
		free(player);
}
void	free_game(t_game *game)
{
	if (!game)
		return;
	// Free each component
	free_map(game->map);
	free_texture(game->txt);
	free_player(game->player);
}


