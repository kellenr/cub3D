/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:32:22 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/23 01:37:13 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_ra(t_ray *ray)
// {
// 	ray->camera_x = 0;
// 	ray->ray_dir_x = 0;
// 	ray->ray_dir_y = 0;
// 	ray->map_x = 0;
// 	ray->map_y = 0;
// 	ray->side_dist_x = 0;
// 	ray->side_dist_y = 0;
// 	ray->delta_dist_x = 0;
// 	ray->delta_dist_y = 0;
// 	ray->perp_wall_dist = 0;
// 	ray->step_x = 0;
// 	ray->step_y = 0;
// 	ray->hit = 0;
// 	ray->side = 0;
// 	ray->line_height = 0;
// 	ray->draw_start = 0;
// 	ray->draw_end = 0;
// 	ray->wall_x = 0;
// 	ray->tex_x = 0;
// 	ray->tex_y = 0;
// 	ray->step = 0;
// 	ray->tex_pos = 0;
// }

void	init_ray(t_ray *ray, t_game *game, int x)
{
	// init_ra(ray);
	ray->camera_x = 2 * x / (double)W_WIDTH - 1; // Map x-coordinate to camera plane
	ray->ray_dir_x = game->player->dir_x + game->player->plane_x * ray->camera_x;
	ray->ray_dir_y = game->player->dir_y + game->player->plane_y * ray->camera_x;
	ray->map_x = (int)game->player->x; // Player's position in map grid (X)
	ray->map_y = (int)game->player->y; // Player's position in map grid (Y)
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x); // Distance between grid lines
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0; // Initialize wall hit to false
	ray->side = 0;
}

void	calculate_step_and_side_dist(t_ray *ray, t_game *game)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player->y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		// Jump to next map square, either in x-direction or y-direction
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
		// Boundary Checks
		if (ray->map_x < 0 || ray->map_x >= game->map->width ||
			ray->map_y < 0 || ray->map_y >= game->map->height)
		{
			printf("Ray went out of map bounds at (%d, %d).\n", ray->map_x, ray->map_y);
			ray->perp_wall_dist = 1e30; // Assign a very large distance
			break;
		}
		// Check if ray has hit a wall
		if (game->map->map_data[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall_height(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->x + (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->y + (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	// Ensure perp_wall_dist is positive to avoid negative line heights
	// ray->perp_wall_dist = fabs(ray->perp_wall_dist);

	// // Prevent division by zero
	// if (ray->perp_wall_dist < 0.0001)
	// 	ray->perp_wall_dist = 0.0001;
	ray->line_height = (int)(W_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_end >= W_HEIGHT)
		ray->draw_end = W_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycast(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < W_WIDTH)
	{
		init_ray(&ray, game, x);
		calculate_step_and_side_dist(&ray, game);
		perform_dda(&ray, game);
		calculate_wall_height(&ray, game->player);
		draw_line(game, game->txt, &ray, x);
		x++;
	}
	return (0);
}
