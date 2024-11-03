/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:20:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 20:27:45 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game *game, char *line)
{
/* 	char	**tmp;
	int		i;

	tmp = ft_split(line, ' ');
	if (!tmp)
		ft_error("Failed to split map line");
	i = 0;
	while (tmp[i])
	{
		if (ft_strlen(tmp[i]) != game->map->width)
		{
			free_split(tmp);
			ft_error("Map line is not the same length as the first line");
		}
		i++;
	}
	game->map->map_data = ft_realloc(game->map->map_data, game->map->height + 1);
	if (!game->map->map_data)
	{
		free_split(tmp);
		ft_error("Failed to reallocate memory for map");
	}
	game->map->map_data[game->map->height] = tmp;
	game->map->height++; */
}
