/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:48:09 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/22 20:12:31 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: draw_map_square
 * ------------------------
 * Draws a square on the minimap
 *
 * game: The game state
 * x, y: Map coordinates
 * color: Color of the square
 */
void	draw_map_square(t_game *game, int x, int y, int color)
{
	int	pixel_x;
	int	pixel_y;
	int	i;
	int	j;

	pixel_x = x * MINI_CELL_SIZE;
	pixel_y = y * MINI_CELL_SIZE;
	i = 0;
	while (i < MINI_CELL_SIZE)
	{
		j = 0;
		while (j < MINI_CELL_SIZE)
		{
			put_pixel(game, pixel_x + i, pixel_y + j, color);
			j++;
		}
		i++;
	}
}

/*
 * Function: draw_player
 * -------------------------------
 * Draws the player as a small circle on the minimap
 *
 * game: The game state
 */
void	draw_player(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	radius;

	radius = PLAYER_DOT_SIZE / 2;
	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				put_pixel(game, x + i, y + j, COLOR_PLAYER);
			j++;
		}
		i++;
	}
}

// Draw direction line - part 1: prepare variables
void	draw_direction_line(t_game *game, int start_x, int start_y)
{
	int	pos[2];
	int	end[2];
	int	delta[2];

	pos[0] = start_x;
	pos[1] = start_y;
	calc_dir_endpoint(game, start_x, start_y, end);
	init_line_vars(pos, end, delta, game->step);
	draw_direction_line2(game, pos, end, delta);
}

/*
 * Function: draw_minimap
 * ---------------------
 * Draws the minimap on the screen
 *
 * game: The game state
 */
static int	get_minimap_color(char tile)
{
	if (tile == '1')
		return (COLOR_WALL);
	if (tile == '0')
		return (COLOR_FLOOR);
	if (tile == 'D')
		return (0x00FF00);
	return (COLOR_FLOOR);
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	map_height;

	map_height = game->map->height;
	y = 0;
	while (y < map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map->map_data[y]))
		{
			if (game->map->map_data[y][x] != ' ')
				draw_map_square(game, x, y,
					get_minimap_color(game->map->map_data[y][x]));
			x++;
		}
		y++;
	}
	draw_player_on_minimap(game);
}
