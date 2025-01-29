/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:48:09 by keramos-          #+#    #+#             */
/*   Updated: 2025/01/29 20:12:15 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_line(t_game *game, int x1, int y1, int color)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	steps;

	dx = game->player.dir_x * MINI_CELL_SIZE * 4;
	dy = game->player.dir_y * MINI_CELL_SIZE * 4;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x = x1;
	y = y1;
	while (steps--)
	{
		draw_pixel(&game->imgs, x, y, color);
		x += dx / (steps + 1);
		y += dy / (steps + 1);
	}
}

void	draw_cell(int start_x, int start_y, int color, t_game *game)
{
	int	i;
	int	j;
	char	*dst;

	i = 0;
	while (i < MINI_CELL_SIZE)
	{
		j = 0;
		while (j < MINI_CELL_SIZE)
		{
			dst = game->imgs.pix
				+ ((start_y + i) * game->imgs.ln_len
					+ (start_x + j) * (game->imgs.bitp / 8));
			*(unsigned int *)dst = color;
			j++;
		}
		i++;
	}
}

void	render_mini_direction(t_game *game)
{
	int	start_x;
	int	start_y;

	start_x = game->player.x * MINI_CELL_SIZE;
	start_y = game->player.y * MINI_CELL_SIZE;
	// draw_minimap_line(game, start_x, start_y, 0x00FF00);
}

void	render_mini_player(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = game->player.x * MINI_CELL_SIZE - (MINI_PLAYER_SIZE / 2);
	player_y = game->player.y * MINI_CELL_SIZE - (MINI_PLAYER_SIZE / 2);
	draw_cell(player_x, player_y, COLOR_PLAYER, game);
}

void	render_mini_map(t_game *game)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	y = 0;
	while (game->map->map_data[y])
	{
		x = 0;
		while (game->map->map_data[y][x])
		{
			start_x = x * MINI_CELL_SIZE;
			start_y = y * MINI_CELL_SIZE;
			if (game->map->map_data[y][x] == '1')
				draw_cell(start_x, start_y, COLOR_WALL, game);
			else if (game->map->map_data[y][x] == '0')
				draw_cell(start_x, start_y, COLOR_FLOOR, game);
			else if (game->map->map_data[y][x] == ' ')
				draw_cell(start_x, start_y, 0xAAAAAA, game);
			else if (game->map->map_data[y][x] == 'D') // ✅ Add doors
				draw_cell(start_x, start_y, 0xAA5500, game);
			else
				draw_cell(start_x, start_y, 0xFFFFFF, game);
			x++;
		}
		y++;
	}
}

void	render_mini(t_game *game)
{
	render_mini_map(game);
	render_mini_player(game);
	render_mini_direction(game);
}