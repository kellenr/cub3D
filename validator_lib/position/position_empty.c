/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:10:23 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/14 10:11:17 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_validator.h"

/**
 * Checks if a position is empty
 */
bool	val_is_position_empty(int x, int y, t_val_cubfile *cubfile)
{
	if (!val_is_position_valid(x, y, cubfile))
		return (false);
	return (cubfile->map.grid[y][x] == '0');
}