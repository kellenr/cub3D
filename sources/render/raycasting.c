/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:32:22 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/27 19:29:27 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_game *game, int x)
{
	game->ray.camera_x = 2 * x / (double)W_WIDTH - 1;
	game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x * \
		game->ray.camera_x;
	game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y * \
		game->ray.camera_x;
	game->ray.map_x = (int)game->player.x;
	game->ray.map_y = (int)game->player.y;
	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	game->ray.hit = 0;
	game->ray.side = 0;
}

void	calculate_step(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.x - game->ray.map_x) * \
			game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.x) * \
			game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.y - game->ray.map_y) * \
			game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.y) * \
			game->ray.delta_dist_y;
	}
}

void	perform_dda(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map->map_data[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

void	calculate_wall(t_game *game)
{

	if (game->ray.side == 0)
		game->ray.perp_wall_dist = (game->ray.map_x - game->player.x + \
			(1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
	else
		game->ray.perp_wall_dist = (game->ray.map_y - game->player.y + \
			(1 - game->ray.step_y) / 2) / game->ray.ray_dir_y;
	game->ray.line_height = (int)(W_HEIGHT / game->ray.perp_wall_dist);
	game->ray.draw_start = -game->ray.line_height / 2 + W_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + W_HEIGHT / 2;
	if (game->ray.draw_end >= W_HEIGHT)
		game->ray.draw_end = W_HEIGHT - 1;
	coordinate_texture(game);

}

int	raycast(t_game *game)
{
	int	x;

	x = 0;
	render_frame(game);
	while (x < W_WIDTH)
	{
		cast_ray(game, x);
		calculate_step(game);
		perform_dda(game);
		calculate_wall(game);
		correct_texture(game);
		draw_line(game, x);
		x++;
	}
	return (0);
}
