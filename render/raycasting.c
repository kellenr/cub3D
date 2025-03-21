/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:32:22 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:17:19 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function: calculate_ray
 * -----------------------
 * Sets up ray direction and initial values for a screen column
 *
 * game: The game state
 * ray: The ray structure to set up
 * x: The x-coordinate on the screen
 */
void	calculate_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / (double)W_WIDTH - 1.0;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	ray->delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	ray->delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	ray->hit = 0;
}

/*
 * Function: calculate_step_and_side_dist
 * --------------------------------------
 * Calculate step direction and initial side distance
 *
 * game: The game state
 * ray: The ray structure to update
 */
void	calculate_step_and_side_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x) * \
			ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y) * \
			ray->delta_dist_y;
	}
}

/*
 * Function: perform_dda
 * ---------------------
 * Digital Differential Analysis algorithm to find wall hits
 *
 * game: The game state
 * ray: The ray structure to update
 */
void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map->map_data[ray->map_y][ray->map_x] == '1' || \
			(game->map->map_data[ray->map_y][ray->map_x] == 'D'))
		{
			ray->hit = 1;
			ray->wall = game->map->map_data[ray->map_y][ray->map_x];
		}
	}
}

/*
 * Function: calculate_wall_distance
 * --------------------------------
 * Calculate distance to the wall for the current ray
 *
 * game: The game state
 * ray: The ray structure to update
 */
void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(W_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_end >= W_HEIGHT)
		ray->draw_end = W_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

/*
 * Function: cast_rays
 * ------------------
 * Main raycasting function that casts rays for each column of the screen
 *
 * game: The game state
 */
void	cast_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < W_WIDTH)
	{
		calculate_ray(game, &game->ray, x);
		calculate_step_and_side_dist(game, &game->ray);
		perform_dda(game, &game->ray);
		calculate_wall_distance(game, &game->ray);
		determine_texture(game, &game->ray);
		draw_vertical_line(game, x);
		x++;
	}
}
