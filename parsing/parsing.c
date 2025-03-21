/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:18:14 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 00:10:15 by kellen           ###   ########.fr       */
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
	game->fd = open_file(filename);
	init_map(game);
	parse_content(game);
	close(game->fd);
	game->fd = open_file(filename);
	line_jump(game);
	parse_map(game);
	close(game->fd);
	initialize_player(game);
}
