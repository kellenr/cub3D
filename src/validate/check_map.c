/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:14 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/30 16:09:42 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: get_map_char
 * ----------------------
 * Returns the character at the given row and column indices.
 * If the indices are out of bounds, returns a space (' ').
 *
 * map: Pointer to the map structure.
 * row: The row index.
 * col: The column index.
 *
 * returns: The character at the given indices.
 * 		If out of bounds, returns a space (' ').
 */
char	get_map_char(t_map *map, int row, int col)
{
	int	row_length;

	if (row < 0 || row >= map->height)
		return (' ');
	if (col < 0)
		return (' ');
	row_length = strlen(map->map_data[row]);
	if (col >= row_length)
		return (' ');
	return (map->map_data[row][col]);
}

/*
 * Function: is_valid_char
 * -----------------------
 * Checks if the given character is one of the allowed map characters or a
 * space.
 *
 * c: The character to validate.
 *
 * returns: 1 if valid, 0 otherwise.
 */
int	is_valid_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' ||
		c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
 * Function: check_adjacents_not_void
 * ----------------------------------
 * Ensures that the character at (row, col) is not adjacent to a space (' ').
 *
 * map: Pointer to the map structure.
 * row: The current row index.
 * col: The current column index.
 *
 * returns: 1 if no adjacent space, 0 otherwise.
 */
int	check_adjacents_not_void(t_map *map, int row, int col)
{
	int	delta_row;
	int	delta_col;

	delta_row = -1;
	while (delta_row <= 1)
	{
		delta_col = -1;
		while (delta_col <= 1)
		{
			if (delta_row == 0 && delta_col == 0)
			{
				delta_col++;
				continue ;
			}
			if (get_map_char(map, row + delta_row, col + delta_col) == ' ')
				ft_error("Invalid map layout!");
			delta_col++;
		}
		delta_row++;
	}
	return (1);
}

/*
 * Function: is_map_enclosed
 * -------------------------
 * Validates that the map is enclosed by walls and contains only
 * allowed characters.
 *
 * map: Pointer to the map structure.
 *
 * returns: 1 if the map is properly enclosed, 0 otherwise.
 */
int	is_map_enclosed(t_map *map)
{
	int	row;
	int	col;
	int	player_count;

	if (map == NULL || map->height == 0 || map->width == 0)
		return (0);
	player_count = 0;
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			char	current;

			current = get_map_char(map, row, col);
			if (!is_valid_char(current))
				ft_error("Invalid character in map!");
			if (current == 'N' || current == 'S' ||
				current == 'E' || current == 'W')
				player_count++;
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
			col++;
		}
		row++;
	}
	if (player_count != 1)
	{
		if (player_count == 0)
			ft_error("No player position found in map!");
		else
			ft_error("Multiple player positions found in map!");
	}
	return (1);
}





int	validate_map(t_game *game)
{
	if (!is_map_enclosed(game->map))
	{
		// free_map(game->map);
		// free_game(game);
		ft_error("The map is not enclosed by walls!");
	}
	return (1);
}
