/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:00:23 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/14 10:01:17 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_validator.h"

/**
 * Checks if a position contains the player
 */
bool	val_is_position_player(int x, int y, t_val_cubfile *cubfile)
{
	if (!val_is_position_valid(x, y, cubfile))
		return (false);
	return (cubfile->map.grid[y][x] == 'N' ||
			cubfile->map.grid[y][x] == 'S' ||
			cubfile->map.grid[y][x] == 'E' ||
			cubfile->map.grid[y][x] == 'W');
}