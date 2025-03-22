/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:32:22 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/22 20:12:38 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: determine_texture
 * ---------------------------
 * Determine which texture to use based on the wall orientation
 *
 * game: The game state
 * ray: The ray structure to update
 */
void	determine_texture(t_game *game, t_ray *ray)
{
	if (ray->wall == 'D')
	{
		ray->texture = &game->txt.d;
		return ;
	}
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->texture = &game->txt.ea;
		else
			ray->texture = &game->txt.we;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->texture = &game->txt.so;
		else
			ray->texture = &game->txt.no;
	}
}

/*
 * Function: render_frame
 * ---------------------
 * Renders a complete frame of the game
 *
 * game: The game state
 */
void	render_frame(t_game *game)
{
	cast_rays(game);
	if (game->mini_active)
		draw_minimap(game);
	if (game->mini_scoop)
		draw_mini_viewport(game);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.img, 0, 0);
}

// Calculate player direction endpoint
void	calc_dir_endpoint(t_game *game, int start_x, int start_y, int end[2])
{
	end[0] = start_x + (int)(game->player.dir_x * MINI_CELL_SIZE);
	end[1] = start_y + (int)(game->player.dir_y * MINI_CELL_SIZE);
}

void	draw_player_on_minimap(t_game *game)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = (int)(game->player.x * MINI_CELL_SIZE);
	pixel_y = (int)(game->player.y * MINI_CELL_SIZE);
	draw_player(game, pixel_x, pixel_y);
	draw_direction_line(game, pixel_x, pixel_y);
}
