/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:09:11 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/24 22:21:41 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x + game->player->dir_x * MOVE_SPEED;
	new_y = game->player->y + game->player->dir_y * MOVE_SPEED;
	if (game->map->map_data[(int)(new_y)][(int)(game->player->x)] != '1' && \
			game->map->map_data[(int)(game->player->y)][(int)(new_x)] != '1')
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x - game->player->dir_x * MOVE_SPEED;
	new_y = game->player->y - game->player->dir_y * MOVE_SPEED;
	if (game->map->map_data[(int)(new_y)][(int)(game->player->x)] != '1' && \
			game->map->map_data[(int)(game->player->y)][(int)(new_x)] != '1')
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x - game->player->plane_x * MOVE_SPEED;
	new_y = game->player->y - game->player->plane_y * MOVE_SPEED;
	if (game->map->map_data[(int)(new_y)][(int)(game->player->x)] != '1' && \
			game->map->map_data[(int)(game->player->y)][(int)(new_x)] != '1')
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x + game->player->plane_x * MOVE_SPEED;
	new_y = game->player->y + game->player->plane_y * MOVE_SPEED;
	if (game->map->map_data[(int)(new_y)][(int)(game->player->x)] != '1' && \
			game->map->map_data[(int)(game->player->y)][(int)(new_x)] != '1')
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

/*
 * This function call all the movement functions
 * and rotate functions based on the keys pressed
 * by the user.
 */
void	handle_movement(t_game *game)
{
	if (game->keys.forward)
		move_forward(game);
	if (game->keys.backward)
		move_backward(game);
	if (game->keys.left)
		move_left(game);
	if (game->keys.right)
		move_right(game);
	if (game->keys.rotate_left)
		rotate_left(game);
	if (game->keys.rotate_right)
		rotate_right(game);
}
