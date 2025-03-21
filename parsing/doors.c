/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:02:11 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:13:32 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: toggle_door
 * --------------------
 * Toggles the door state (open/closed) in front of the player
 *
 * game: The game state
 */
void	toggle_door(t_game *game)
{
	int	check_x;
	int	check_y;

	check_x = (int)(game->player.x + game->player.dir_x);
	check_y = (int)(game->player.y + game->player.dir_y);
	if (game->map->map_data[check_y][check_x] == 'D')
	{
		game->map->map_data[check_y][check_x] = 'd';
		ft_printf("🚪 Door opened!\n");
	}
	else if (game->map->map_data[check_y][check_x] == 'd')
	{
		if ((game->map->map_data[check_y][check_x - 1] == '1' && \
			game->map->map_data[check_y][check_x + 1] == '1') || \
			(game->map->map_data[check_y - 1][check_x] == '1' && \
			game->map->map_data[check_y + 1][check_x] == '1'))
		{
			game->map->map_data[check_y][check_x] = 'D';
			ft_printf("🚪 Door closed!\n");
		}
	}
}
