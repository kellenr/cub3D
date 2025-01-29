/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:33:03 by keramos-          #+#    #+#             */
/*   Updated: 2025/01/29 20:01:43 by keramos-         ###   ########.fr       */
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
		c == 'N' || c == 'S' || c == 'E' ||
		c == 'W' || c == 'D')
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
			{
				free_map(map); // free texture
				ft_error("Invalid map layout!");
			}
			delta_col++;
		}
		delta_row++;
	}
	return (1);
}
