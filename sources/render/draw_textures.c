/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:32:22 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/27 19:38:02 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ; // Ignore pixels outside the screen
	dst = img->pix + (y * img->ln_len + x * (img->bitp / 8));
	*(unsigned int *)dst = color;
}

void	coordinate_texture(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.wall_x = game->player.y + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		game->ray.wall_x = game->player.x + game->ray.perp_wall_dist * game->ray.ray_dir_x;
	game->ray.wall_x -= floor(game->ray.wall_x);
	game->ray.tex_x = (int)(game->ray.wall_x * (double)game->txt.size);
	if (game->ray.side == 0 && game->ray.ray_dir_x < 0)
		game->ray.tex_x = game->txt.size - game->ray.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y > 0)
		game->ray.tex_x = game->txt.size - game->ray.tex_x - 1;
}

void	correct_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
		{
			game->ray.wall = game->txt.ea.pix;
			game->txt.bitp = game->txt.ea.bitp; // Update bitp
		}
		else
		{
			game->ray.wall = game->txt.we.pix;
			game->txt.bitp = game->txt.we.bitp; // Update bitp
		}
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
		{
			game->ray.wall = game->txt.so.pix;
			game->txt.bitp = game->txt.so.bitp; // Update bitp
		}
		else
		{
			game->ray.wall = game->txt.no.pix;
			game->txt.bitp = game->txt.no.bitp; // Update bitp
		}
	}
}

void	draw_line(t_game *game, int x)
{
	int	y;
	int	color;
	int	bitp;

	bitp = game->txt.bitp;
	game->ray.step = 1.0 * game->txt.size / game->ray.line_height;
	game->ray.tex_pos = (game->ray.draw_start - W_HEIGHT / 2 + game->ray.line_height / 2) * game->ray.step;
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		game->ray.tex_y = (int)game->ray.tex_pos & (game->txt.size - 1);
		game->ray.tex_pos += game->ray.step;
		color = *(unsigned int *)(game->ray.wall + (game->ray.tex_y * game->txt.size + game->ray.tex_x) * (bitp / 8));
		draw_pixel(&game->imgs, x, y, color);
		y++;
	}
}

/*
	int	y;
	int	color;

	y = 0;
	if (game->ray.side == 1)
		color = 0x800080; // purple for horizontal walls
	else
		color = 0xFFC0CB; // pink for vertical walls
	while (y < game->ray.draw_start) // Draw ceiling
	{
		draw_pixel(&game->imgs, x, y, game->txt.ceiling_color); // Sky blue color
		y++;
	}
	while (y < game->ray.draw_end) // Draw the wall
	{
		draw_pixel(&game->imgs, x, y, color);
		y++;
	}
	while (y < W_HEIGHT) // Draw floor
	{
		draw_pixel(&game->imgs, x, y, game->txt.floor_color); // Green color for floor
		y++;
	}
 */
