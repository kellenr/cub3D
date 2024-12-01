/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:14 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/27 01:15:09 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * All this functions are used to validate the map
 * if is close, if the player is in the map, if the map is valid
 * and if the map is valid layout
 * if the caracters are valid etc..
 */
int	validate_map_initial(t_map *map)
{
	if (map == NULL || map->height == 0 || map->width == 0)
		return (0);
	return (1);
}

int	validate_player_count(int player_count)
{
	if (player_count != 1)
	{
		if (player_count == 0)
			ft_error("No player position found in map!"); // free structure
		else
			ft_error("Multiple player positions found in map!"); // free structure
	}
	return (1);
}

int	process_cell(t_map *map, int row, int col, int *player_count)
{
	char	current;

	current = get_map_char(map, row, col);
	if (!is_valid_char(current))
	{
		free_map(map);
		ft_error("Invalid character in map!"); // free texture and player
	}
	if (current == 'N' || current == 'S' ||
		current == 'E' || current == 'W')
		(*player_count)++;
	if (current != ' ')
	{
		if (row == 0 || row == map->height - 1 ||
			col == 0 || col == map->width - 1)
		{
			if (current != '1')
				return (0);
		}
		if (current != '1' && !check_adjacents_not_void(map, row, col))
			return (0);
	}
	return (1);
}

int	is_map_enclosed(t_map *map)
{
	int		row;
	int		col;
	int		player_count;

	if (!validate_map_initial(map))
		return (0);
	player_count = 0;
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (!process_cell(map, row, col, &player_count))
				return (0);
			col++;
		}
		row++;
	}
	return (validate_player_count(player_count));
}

/*
 * Function: validate_map
 * ----------------------
 * Validates the map by checking if it is enclosed by walls and contains only allowed
 * characters.
 *
 * game: Pointer to the game structure.
 *
 * returns: 1 if the map is valid, 0 otherwise.
 */
int	validate_map(t_game *game)
{
	if (!is_map_enclosed(game->map))
	{
		free_map(game->map); // free 1 bit from get the next line
		ft_error("The map is not enclosed by walls!");
	}
	return (1);
}
