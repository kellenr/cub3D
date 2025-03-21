/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:06 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 07:49:34 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to parse the texture identifiers and colors from the file.
 * Expects a line with one of the following identifiers:
 * NO, SO, WE, EA, F, C
 * Parses the corresponding texture or color value and stores it in the
 * txt structure.
 * Returns 1 if the identifier is valid, 0 otherwise.
 * If the identifier is not recognized, the function does nothing.
 */
int	parse_texture(t_game *game)
{
	if (ft_strncmp(game->n_line, "NO", 2) == 0)
	{
		if (game->txt.north)
		{
			clean_error(game, "Duplicate NO identifier.");
		}
		game->txt.north = get_texture_path(game, 2);
	}
	else if (ft_strncmp(game->n_line, "SO", 2) == 0)
	{
		if (game->txt.south)
		{
			clean_error(game, "Duplicate SO identifier.");
		}
		game->txt.south = get_texture_path(game, 2);
	}
	else
		return (parse_texture2(game));
	return (1);
}

int	parse_texture2(t_game *game)
{
	if (ft_strncmp(game->n_line, "WE", 2) == 0)
	{
		if (game->txt.west)
		{
			clean_error(game, "Duplicate WE identifier.");
		}
		game->txt.west = get_texture_path(game, 2);
	}
	else if (ft_strncmp(game->n_line, "EA", 2) == 0)
	{
		if (game->txt.east)
		{
			clean_error(game, "Duplicate EA identifier.");
		}
		game->txt.east = get_texture_path(game, 2);
	}
	else if (!game->txt.north || !game->txt.south || \
				!game->txt.west || !game->txt.east)
		id_missing(game);
	else
		return (parse_colors(game));
	return (1);
}

int	parse_colors(t_game *game)
{
	if (game->n_line[0] == 'F')
	{
		if (game->txt.floor_color != -1)
		{
			clean_error(game, "Duplicate floor color identifier.");
		}
		game->txt.floor_color = extract_rgb(game);
	}
	else if (game->n_line[0] == 'C')
	{
		if (game->txt.ceiling_color != -1)
		{
			clean_error(game, "Duplicate ceiling color identifier.");
		}
		game->txt.ceiling_color = extract_rgb(game);
	}
	return (1);
}
