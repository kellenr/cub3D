/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:32:22 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:18:56 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: put_pixel
 * ------------------
 * Puts a pixel with a specific color at the specified coordinates
 *
 * game: The game state
 * x: The x-coordinate on the screen
 * y: The y-coordinate on the screen
 * color: The color to put as an int
 */
void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= W_WIDTH || y >= W_HEIGHT)
		return ;
	dst = game->imgs.pix + (y * game->imgs.ln_len + x * (game->imgs.bitp / 8));
	*(unsigned int *)dst = color;
}

/*
 * Function: draw_ceiling
 * ---------------------
 * Draws the ceiling portion of a vertical line on the screen
 *
 * game: The game state
 * x: The x-coordinate on the screen (column)
 * y_start: The y-coordinate to start drawing
 */
void	draw_ceiling(t_game *game, int x, int y_end)
{
	int	y;

	y = 0;
	while (y < y_end)
	{
		put_pixel(game, x, y, game->txt.ceiling_color);
		y++;
	}
}

/*
 * Function: draw_floor
 * -------------------
 * Draws the floor portion of a vertical line on the screen
 *
 * game: The game state
 * x: The x-coordinate on the screen (column)
 * y_start: The y-coordinate to start drawing from
 */
void	draw_floor(t_game *game, int x, int y_start)
{
	int	y;

	y = y_start;
	while (y < W_HEIGHT)
	{
		put_pixel(game, x, y, game->txt.floor_color);
		y++;
	}
}

/*
 * Function: draw_wall_textured
 * ---------------------------
 * Draws a textured wall segment at the specified screen column
 *
 * game: The game state
 * x: The x-coordinate on the screen (column)
 */
void	draw_wall_textured(t_game *game, int x)
{
	int		y;
	int		color;
	t_ray	*ray;
	t_imgs	*txt_img;

	ray = &game->ray;
	txt_img = ray->texture;
	ray->tex_x = (int)(ray->wall_x * game->txt.size);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || \
		(ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = game->txt.size - ray->tex_x - 1;
	ray->step = 1.0 * game->txt.size / ray->line_height;
	ray->tex_pos = (ray->draw_start - W_HEIGHT / 2 + ray->line_height / 2) \
		* ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (game->txt.size - 1);
		ray->tex_pos += ray->step;
		color = *(unsigned int *)(txt_img->pix + txt_img->ln_len * ray->tex_y \
			+ ray->tex_x * (txt_img->bitp / 8));
		put_pixel(game, x, y, color);
		y++;
	}
}

/*
 * Function: draw_vertical_line
 * ---------------------------
 * Draws a complete vertical line on the screen including ceiling, wall,
 * and floor
 *
 * game: The game state
 * x: The x-coordinate on the screen (column)
 */
void	draw_vertical_line(t_game *game, int x)
{
	draw_ceiling(game, x, game->ray.draw_start);
	draw_wall_textured(game, x);
	draw_floor(game, x, game->ray.draw_end);
}
