/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:02:11 by keramos-          #+#    #+#             */
/*   Updated: 2025/01/29 20:46:24 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_txt_bonus(t_game *game)
{
	game->txt.door = ft_strdup("textures/door.xpm");  // ✅ Hardcoded door texture
	init_txt_path(game, &game->txt.door_img, game->txt.door);
}


void	toggle_door(t_game *game)
{
	int	check_x;
	int	check_y;

	check_x = (int)(game->player.x + game->player.dir_x);
	check_y = (int)(game->player.y + game->player.dir_y);
	if (game->map->map_data[check_y][check_x] == 'D')
		game->map->map_data[check_y][check_x] = '0'; // Open door
	else if (game->map->map_data[check_y][check_x] == '0')
		game->map->map_data[check_y][check_x] = 'D'; // Close door
}
