/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_validator_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:20:42 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/15 19:20:42 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Sets player information in the cubfile
 */
void	set_player(t_val_cubfile *cubfile, char c, int x, int y)
{
	cubfile->map.has_player = true;
	cubfile->map.player_dir = c;
	cubfile->map.player_x = x;
	cubfile->map.player_y = y;
}

/**
 * Finds and validates player position in the map
 */
bool	val_find_player(t_val_cubfile *cubfile)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < cubfile->map.height)
	{
		x = 0;
		while (x < (int)ft_strlen(cubfile->map.grid[y]))
		{
			c = cubfile->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (cubfile->map.has_player)
				{
					val_set_error(cubfile, "Multiple player positions in map");
					return (false);
				}
				set_player(cubfile, c, x, y);
			}
			x++;
		}
		y++;
	}
	return (true);
}

/**
 * Validates the map structure
 */
bool	val_validate_map(t_val_cubfile *cubfile)
{
	if (cubfile->map.height == 0 || cubfile->map.width == 0)
	{
		val_set_error(cubfile, "Map is empty");
		return (false);
	}
	if (!val_find_player(cubfile))
		return (false);
	if (!val_check_player_position(cubfile))
		return (false);
	
	// Temporarily disabled wall enclosure check
	// if (!val_check_map_closed(cubfile))
	//	return (false);
	
	return (true);
}