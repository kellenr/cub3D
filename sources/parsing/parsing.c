/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:18:14 by keramos-          #+#    #+#             */
/*   Updated: 2025/02/03 20:05:39 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to parse the map file.
 * validate the map, the textures and the colors.
 * and initialize the player.
 *
 * Found the position of the player in the map.
 */
void	parse_file(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open_file(filename);
	init_map(game);
	line = parse_texture_and_colors(fd, &game->txt);
	load_map(fd, game->map, line);
	close(fd);
	validate_map(game);
	initialize_player(game);
	free(line);
}
