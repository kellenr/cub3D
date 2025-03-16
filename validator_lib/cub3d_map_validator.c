/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:49:18 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:28:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Checks if a character is valid in the map
 */
bool	val_is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'D');
}

/**
 * Checks if a position is valid (within map bounds)
 */
bool	val_is_position_valid(int x, int y, t_val_cubfile *cubfile)
{
	return (x >= 0 && x < cubfile->map.width
		&& y >= 0 && y < cubfile->map.height);
}

/**
 * Checks if the player position is valid
 */
bool	val_check_player_position(t_val_cubfile *cubfile)
{
	if (!cubfile->map.has_player)
	{
		val_set_error(cubfile, "No player position in map");
		return (false);
	}
	return (true);
}

/**
 * Check if a character represents a walkable space or player position
 */
bool	val_is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'D');
}

/**
 * Check if a map position is enclosed by walls
 */
bool	val_check_position_enclosed(int x, int y, t_val_cubfile *cubfile)
{
	char	c;
	int		dirs[8][2] = {
		{0, -1}, {1, -1}, {1, 0}, {1, 1},
		{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
	};
	int		i, nx, ny;

	c = cubfile->map.grid[y][x];
	if (!val_is_walkable(c))
		return (true);

	for (i = 0; i < 8; i++)
	{
		nx = x + dirs[i][0];
		ny = y + dirs[i][1];

		/* Check if the position is within map bounds */
		if (ny < 0 || ny >= cubfile->map.height)
		{
			val_set_error(cubfile, "Map not completely enclosed by walls");
			return (false);
		}

		/* Check if the position is within the row length (handles irregular maps) */
		int row_len = ft_strlen(cubfile->map.grid[ny]);
		if (nx < 0 || nx >= row_len)
		{
			/* If checking outside the map boundary and the current position is a wall, that's ok */
			if (nx < 0 || cubfile->map.grid[y][x] == '1')
				continue;
			val_set_error(cubfile, "Map not completely enclosed by walls");
			return (false);
		}

		/* Only check if the grid character is a space (void) */
		if (cubfile->map.grid[ny][nx] == ' ')
		{
			/* If only checking diagonal and both orthogonal directions are walls, that's ok */
			if ((dirs[i][0] != 0 && dirs[i][1] != 0) && 
			    ((ny < cubfile->map.height && nx < row_len && cubfile->map.grid[y][nx] == '1') || 
			     (ny < cubfile->map.height && nx < row_len && cubfile->map.grid[ny][x] == '1')))
				continue;
			val_set_error(cubfile, "Map not completely enclosed by walls");
			return (false);
		}
	}
	
	return (true);
}

/**
 * Validates specifically the unclosed map at row 5
 */
bool	val_check_specific_issue(t_val_cubfile *cubfile)
{
	// This function no longer needed - returning true to avoid special case handling
	(void)cubfile; // Suppress unused parameter warning
	return (true);
}

/**
 * Checks if the map is closed/surrounded by walls
 */
bool	val_check_map_closed(t_val_cubfile *cubfile)
{
	int	x, y;

	// Standard validation for all positions
	for (y = 0; y < cubfile->map.height; y++)
	{
		int row_len = ft_strlen(cubfile->map.grid[y]);
		for (x = 0; x < row_len; x++)
		{
			// Only check positions with walkable spaces or player
			if (val_is_walkable(cubfile->map.grid[y][x]) && 
			    !val_check_position_enclosed(x, y, cubfile))
				return (false);
		}
	}

	return (true);
}