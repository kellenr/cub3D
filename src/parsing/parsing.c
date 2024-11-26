/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:18:14 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/25 00:54:06 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to parse the map file and initialize the game structure.
 * game: Pointer to the game structure
 * filename: Name of the map file
 * Returns nothing
 */
void	parse_file(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open_file(filename);        // Open the file
	init_txt(game);      // Initialize the texture structure
	init_map(game);      // Initialize the map structure
	line = check_texture(fd, game->txt);    // Parse textures and colors
	load_map(fd, game->map, line);         // Parse the map
	close(fd);                      // Close the file
	validate_map(game);             // Validate the map
	init_player(game);
	initialize_player(game);
}
