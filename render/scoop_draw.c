/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoop_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:04:56 by kellen            #+#    #+#             */
/*   Updated: 2025/03/22 19:35:41 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_scoop_map_tiles(t_game *game)
{
	int		x;
	int		y;
	int		color;
	char	tile;

	y = 0;
	while (y < SCOOP_SIZE)
	{
		x = 0;
		while (x < SCOOP_SIZE)
		{
			tile = get_map_tile(game, \
				((int)game->player.x) + (x - SCOOP_SIZE / 2), \
				((int)game->player.y) + (y - SCOOP_SIZE / 2));
			color = get_tile_color(tile);
			draw_map_square_scoop(game, x * MINI_SCOOP_CELL_SIZE, \
				y * MINI_SCOOP_CELL_SIZE, color);
			x++;
		}
		y++;
	}
}

void	draw_scoop_background(t_game *game)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;
	int	dim;

	calculate_scoop_position(&pos_x, &pos_y);
	dim = SCOOP_SIZE * MINI_SCOOP_CELL_SIZE;
	y = 0;
	while (y < dim)
	{
		x = 0;
		while (x < dim)
		{
			put_pixel(game, pos_x + x, pos_y + y, 0x333333);
			x++;
		}
		y++;
	}
}

void	draw_scoop_border(t_game *game)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;
	int	dim;

	calculate_scoop_position(&pos_x, &pos_y);
	dim = SCOOP_SIZE * MINI_SCOOP_CELL_SIZE;
	y = 0;
	while (y < dim)
	{
		put_pixel(game, pos_x, pos_y + y, 0xFFFFFF);
		put_pixel(game, pos_x + dim - 1, pos_y + y, 0xFFFFFF);
		y++;
	}
	x = 0;
	while (x < dim)
	{
		put_pixel(game, pos_x + x, pos_y, 0xFFFFFF);
		put_pixel(game, pos_x + x, pos_y + dim - 1, 0xFFFFFF);
		x++;
	}
}

void	draw_player_in_scoop(t_game *game)
{
	int	pos[2];
	int	center[2];
	int	x;
	int	y;
	int	radius;

	calculate_scoop_position(&pos[0], &pos[1]);
	center[0] = pos[0] + (SCOOP_SIZE / 2) * MINI_SCOOP_CELL_SIZE + \
		MINI_SCOOP_CELL_SIZE / 2;
	center[1] = pos[1] + (SCOOP_SIZE / 2) * MINI_SCOOP_CELL_SIZE + \
		MINI_SCOOP_CELL_SIZE / 2;
	radius = MINI_SCOOP_CELL_SIZE / 2;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				put_pixel(game, center[0] + x, center[1] + y, COLOR_PLAYER);
			x++;
		}
		y++;
	}
}

void	draw_direction_in_scoop(t_game *game)
{
	int		pos[2];
	int		center[2];
	int		line_length;
	int		i;
	double	d[2];

	calculate_scoop_position(&pos[0], &pos[1]);
	center[0] = pos[0] + (SCOOP_SIZE / 2) * MINI_SCOOP_CELL_SIZE + \
		MINI_SCOOP_CELL_SIZE / 2;
	center[1] = pos[1] + (SCOOP_SIZE / 2) * MINI_SCOOP_CELL_SIZE + \
		MINI_SCOOP_CELL_SIZE / 2;
	line_length = MINI_SCOOP_CELL_SIZE * 2;
	d[0] = game->player.dir_x;
	d[1] = game->player.dir_y;
	i = 0;
	while (i < line_length)
	{
		put_pixel(game, center[0] + (int)(d[0] * i),
			center[1] + (int)(d[1] * i), 0xFF0000);
		i++;
	}
}
