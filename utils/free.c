/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:26:57 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:22:50 by kellen           ###   ########.fr       */
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
	if (map)
		free(map);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_textures(t_txt *txt)
{
	if (txt->north)
		free(txt->north);
	if (txt->south)
		free(txt->south);
	if (txt->west)
		free(txt->west);
	if (txt->east)
		free(txt->east);
	if (txt->door)
		free(txt->door);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_textures(&game->txt);
	if (game->map)
		free_map(game->map);
	if (game->mlx)
		free(game->mlx);
}
