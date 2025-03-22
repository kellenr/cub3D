/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_scoop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:00:28 by kellen            #+#    #+#             */
/*   Updated: 2025/03/22 19:57:53 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: calculate_scoop_position
 * ---------------------------------
 * Calculates the position for the scoop minimap in the bottom right corner
 */
void	calculate_scoop_position(int *pos_x, int *pos_y)
{
	int	scoop_width;
	int	scoop_height;

	scoop_width = SCOOP_SIZE * MINI_SCOOP_CELL_SIZE;
	scoop_height = SCOOP_SIZE * MINI_SCOOP_CELL_SIZE;
	*pos_x = W_WIDTH - scoop_width - SCOOP_MARGIN;
	*pos_y = W_HEIGHT - scoop_height - SCOOP_MARGIN;
}

/*
 * Function: draw_map_square_scoop
 * ------------------------------
 * Draws a square on the minimap scoop at the specified position
 */
void	draw_map_square_scoop(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;
	int	pos_x;
	int	pos_y;

	calculate_scoop_position(&pos_x, &pos_y);
	size = MINI_SCOOP_CELL_SIZE;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (x + i >= 0 && x + i < SCOOP_SIZE * size && \
				y + j >= 0 && y + j < SCOOP_SIZE * size)
			{
				put_pixel(game, pos_x + x + i, pos_y + y + j, color);
			}
			j++;
		}
		i++;
	}
}

/*
 * Function: get_map_tile
 * ---------------------
 * Gets the map tile at the specified coordinates
 * Returns ' ' if coordinates are out of bounds
 */
char	get_map_tile(t_game *game, int map_x, int map_y)
{
	if (map_y < 0 || map_y >= game->map->height)
		return (' ');
	if (map_x < 0 || map_x >= (int)ft_strlen(game->map->map_data[map_y]))
		return (' ');
	return (game->map->map_data[map_y][map_x]);
}

/*
 * Function: get_tile_color
 * -----------------------
 * Returns the appropriate color for a map tile
 */
int	get_tile_color(char tile)
{
	if (tile == '1')
		return (COLOR_WALL);
	else if (tile == '0')
		return (COLOR_FLOOR);
	else if (tile == 'D')
		return (0x00FF00);
	else if (tile == 'd')
		return (0x90EE90);
	else if (tile == ' ')
		return (0x000000);
	else
		return (COLOR_FLOOR);
}

/*
 * Function: draw_scoop_minimap
 * --------------------------
 * Draws a scoop view of the minimap (focused area around player)
 */
void	draw_mini_viewport(t_game *game)
{
	draw_scoop_background(game);
	draw_scoop_map_tiles(game);
	draw_player_in_scoop(game);
	draw_direction_in_scoop(game);
	draw_scoop_border(game);
}
