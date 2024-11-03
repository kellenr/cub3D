/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:42:59 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/28 20:01:11 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
char	*trim_trailing_whitespace(char *line)
{
	int len = ft_strlen(line);

	while (len > 0 && ft_isspace(line[len - 1]))
	{
		line[len - 1] = '\0';
		len--;
	}
	return (line);
}

void	load_map(int fd, t_map *map, char *first_line)
{
	char	*line;
	int		i;

	i = 0;
	map->map_data = malloc(sizeof(char *) * MAX_LINES);  // Allocate memory for map data
	if (!map->map_data)
		ft_error("Error: Memory allocation failed for map");
	// If the map parsing started on the first line (in case we didn't break)
	if (first_line)
	{
		map->map_data[i] = ft_strdup(first_line);
		i++;
	}
	// Parse the remaining map lines
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) > 0)
		{
			map->map_data[i] = ft_strdup(trim_whitespace(line)); // Copy the line to map_data
			free(line); // Don't forget to free the line as `get_next_line` allocates memory
			i++;
		}
		else
			free(line); // Free the line if it's empty
		// if (i >= MAX_LINES)
		// 	ft_error("Map exceeds maximum allowed size.");
	}
	map->map_data[i] = NULL;  // Null-terminate the map data array
	map->height = i;  // Set map height based on number of lines read
	calculate_map_dimensions(map);
}

void	store_map_line(t_map *map, char *line, int *row, int *capacity)
{
	// Resize map_data if row exceeds current capacity
	if (*row >= *capacity)
	{
		*capacity *= 2;
		map->map_data = ft_realloc(map->map_data, sizeof(char *) * (*capacity));
		if (!map->map_data)
			ft_error("Failed to resize map data");
	}
	map->map_data[(*row)++] = strdup(line);
}

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




// char	*line;
	// int		row;
	// int		capacity;

	// row = 0;
	// capacity = 10;
	// map->map_data = (char **)malloc(sizeof(char *) * (capacity)); // Define MAX_LINES based on expected max map size
	// if (!map->map_data)
	// 	ft_error("Failed to allocate memory for map data");
	// map->map_data[row++] = ft_strdup(first_line);
	// free(first_line);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	line = trim_whitespace(line);
	// 	if (line[0] == '1' || ft_isspace(line[0]))
	// 	{
	// 		store_map_line(map, line, &row, &capacity);
	// 	}
	// 	free(line);
	// }
	// map->map_data[row] = NULL;  // Null-terminate
	// map->height = row;
	// calculate_map_dimensions(map);
