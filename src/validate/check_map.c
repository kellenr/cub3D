/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:14 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/28 21:34:59 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
 * Checks if the given character is one of the allowed map characters or a space.
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
				return (0);
			delta_col++;
		}
		delta_row++;
	}
	return (1);
}

/*
 * Function: is_map_enclosed
 * -------------------------
 * Validates that the map is enclosed by walls and contains only allowed characters.
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
				return (0);
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
		return (0);
	return (1);
}

int	is_map_enclosed2(t_map *map)
{
	int	i;
	int	j;

	// Check top and bottom rows
	i = 0;
	while (i < map->width)
	{
		if (map->map_data[0][i] != '1' && map->map_data[0][i] != ' ')  // Allow spaces, but enforce '1'
		{
			printf("Map enclosure error at top row, column %d: '%c'\n", i, map->map_data[0][i]);
			return (0);
		}
		if (map->map_data[map->height - 1][i] != '1' && map->map_data[map->height - 1][i] != ' ')
		{
			printf("Map enclosure error at bottom row, column %d: '%c'\n", i, map->map_data[map->height - 1][i]);
			return (0);
		}
		i++;
	}
	// Check leftmost and rightmost columns
	j = 0;
	while (j < map->height)
	{
		if (map->map_data[j][0] != '1' && map->map_data[j][0] != ' ')  // Allow spaces at edges
		{
			printf("Map enclosure error at row %d, leftmost column: '%c'\n", j, map->map_data[j][0]);
			return (0);
		}
		if (map->map_data[j][map->width - 1] != '1' && map->map_data[j][map->width - 1] != ' ')
		{
			printf("Map enclosure error at row %d, rightmost column: '%c'\n", j, map->map_data[j][map->width - 1]);
			return (0);
		}
		j++;
	}

	return (1);
}

int	validate_map_chars(t_map *map)
{
	int		i;
	int		j;
	int		player_count;
	char	c;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->map_data[i][j];
			// Check if character is valid
			if (!ft_strchr("01NSEW ", c))
			{
				ft_printf("Invalid character '%c' found at row %d, column %d\n", c, i, j);
				return (0);  // Return 0 to indicate failure
			}
			// Count player positions
			if (ft_strchr("NSEW", c))
				player_count++;
			j++;
		}
		i++;
	}
	// Ensure exactly one player start position
	if (player_count != 1)
	{
		if (player_count == 0)
			ft_error("No player start position found!");
		else
			ft_error("Multiple player start positions found!");
		return (0);
	}
	return (1);
}

int	is_map_valid_layout(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < map->height - 1)  // Skip the first and last rows
	{
		j = 1;
		while (j < map->width - 1)  // Skip the first and last columns
		{
			c = map->map_data[i][j];
			// Check if it's an empty space or a player start position
			if (c == '0' || ft_strchr("NSEW", c))
			{
				// Check the surroundings: top, bottom, left, right
				if (map->map_data[i - 1][j] == ' ' || map->map_data[i + 1][j] == ' ' ||
					map->map_data[i][j - 1] == ' ' || map->map_data[i][j + 1] == ' ')
				{
					ft_printf("Map layout error: open space next to row %d, column %d\n", i, j);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);  // Return 1 to indicate the layout is valid
}

int	validate_map(t_game *game)
{
	if (!is_map_enclosed(game->map))
	{
		// free_map(game->map);
		// free_game(game);
		ft_error("The map is not enclosed by walls!");
	}
	// if (!validate_map_chars(game->map))
	// {
	// 	// free_map(game->map);
	// 	// free_game(game);
	// 	ft_error("Invalid characters in map!");
	// }
	// if (!is_map_valid_layout(game->map))
	// {
	// 	// free_map(game->map);
	// 	// free_game(game);
	// 	ft_error("Invalid map layout!");

	// }
	return (1);
}
