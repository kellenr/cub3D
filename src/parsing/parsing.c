/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:18:14 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/03 15:21:27 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_file(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	clean_init(game);                // Initialize pointers and values
	fd = open_file(filename);        // Open the file
	game->txt = init_txt(game);      // Initialize the texture structure
	game->map = init_map(game);      // Initialize the map structure
	line = check_texture(fd, game->txt);    // Parse textures and colors
	load_map(fd, game->map, line);         // Parse the map
	close(fd);                      // Close the file
	validate_map(game);             // Validate the map
	game->player = init_player();
	initialize_player(game);        // Initialize the player
}
