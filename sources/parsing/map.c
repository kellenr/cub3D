/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:42:59 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/22 23:20:06 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to load the map from the file descriptor into the map structure.
 * The first line is passed as an argument to avoid reading it again.
 */
void	load_map(int fd, t_map *map, char *first_line)
{
	char	*line;
	int		i;

	i = 0;
	map->map_data = malloc(sizeof(char *) * MAX_LINES);
	if (!map->map_data)
		ft_error("Error: Memory allocation failed for map");
	if (first_line)
	{
		map->map_data[i] = ft_strdup(first_line);
		if (!map->map_data[i])
			ft_error("Error: Memory allocation failed for map line.");
		i++;
	}
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) > 0)
		{
			map->map_data[i] = ft_strdup(trim_whitespace(line));
			if (!map->map_data[i])
				ft_error("Error: Memory allocation failed for map line.");
			free(line);
			i++;
		}
		else
			free(line);
		if (i >= MAX_LINES)
			ft_error("Error: Map exceeds maximum allowed size.");
	}
	map->map_data[i] = NULL;
	map->height = i;
	calculate_map_dimensions(map);
}

/*
 * Function to calculate the width of the map.
 * The width is the length of the longest line in the map.
 * The result is stored in the map structure.
 */
void	calculate_map_dimensions(t_map *map)
{
	int i;
	int line_length;

	i = 0;
	map->width = 0;
	while (i < map->height)
	{
		line_length = ft_strlen(map->map_data[i]);
		if (line_length > map->width)
			map->width = line_length;
		i++;
	}
}

