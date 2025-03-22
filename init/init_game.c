/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:02 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 09:10:48 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to initialize the game structure
 * Initializes the pointers to NULL
 * game: Pointer to the game structure
 * Returns nothing
 */
void	initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	clean_imgs(&game->imgs);
	init_player(&game->player);
	init_txt(&game->txt);
	init_ray(&game->ray);
	init_keys(&game->keys);
	game->start = 0;
	game->fd = 0;
	game->n_line = NULL;
	game->line = 0;
	game->s_map = 0;
	game->e_map = 0;
	game->intro_active = 0;
	game->mini_active = 0;
	game->mini_scoop = 0;
}

/*
 * Function to initialize the map structure
 * Returns a pointer to t_map on success, exits on failure
 */
void	init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_error("Failed to allocate memory for map");
	}
	game->map->map_data = NULL;
	game->map->width = 0;
	game->map->height = 0;
	game->map->num_lines = 0;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->perp_wall_dist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_x = 0;
	ray->step = 0;
	ray->tex_pos = 0;
	ray->wall = '0';
	ray->texture = NULL;
}

void	init_keys(t_keys *keys)
{
	keys->forward = 0;
	keys->backward = 0;
	keys->left = 0;
	keys->right = 0;
	keys->rotate_left = 0;
	keys->rotate_right = 0;
}
