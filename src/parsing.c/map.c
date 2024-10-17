/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:20:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/17 15:57:17 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**load_map(const char *file_path)
{
	int		fd;
	char	*line;
	char	**map_data;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open map file");
	map_data = (char **)malloc(sizeof(char *) * (MAX_LINES + 1)); // Define MAX_LINES based on expected max map size
	if (!map_data)
		ft_error("Memory allocation for map_data failed");
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map_data[i] = ft_strdup(line); // Copy the line to map_data
		free(line); // Don't forget to free the line as `get_next_line` allocates memory
		i++;
		if (i >= MAX_LINES)
			ft_error("Map exceeds maximum allowed size.");
	}
	map_data[i] = NULL; // Null-terminate the array
	close(fd);
	return (map_data);
}


// void	parse_map(t_game *game, char *line)
// {
// /* 	char	**tmp;
// 	int		i;

// 	tmp = ft_split(line, ' ');
// 	if (!tmp)
// 		ft_error("Failed to split map line");
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		if (ft_strlen(tmp[i]) != game->map->width)
// 		{
// 			free_split(tmp);
// 			ft_error("Map line is not the same length as the first line");
// 		}
// 		i++;
// 	}
// 	game->map->map_data = ft_realloc(game->map->map_data, game->map->height + 1);
// 	if (!game->map->map_data)
// 	{
// 		free_split(tmp);
// 		ft_error("Failed to reallocate memory for map");
// 	}
// 	game->map->map_data[game->map->height] = tmp;
// 	game->map->height++; */
// }
