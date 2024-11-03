/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:24 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/03 15:20:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void initialize_player(t_game *game)
{
	int		row;
	int		col;
	char	orientation;

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < (int)ft_strlen(game->map->map_data[row]))
		{
			orientation = game->map->map_data[row][col];
			if (orientation == 'N' || orientation == 'S' || orientation == 'E' || orientation == 'W')
			{
				game->player->x = col + 0.5; // Start in the middle of the cell
				game->player->y = row + 0.5;

				if (orientation == 'N')
				{
					game->player->dir_x = 0;
					game->player->dir_y = -1;
					game->player->plane_x = 0.66;
					game->player->plane_y = 0;
				}
				else if (orientation == 'S')
				{
					game->player->dir_x = 0;
					game->player->dir_y = 1;
					game->player->plane_x = -0.66;
					game->player->plane_y = 0;
				}
				else if (orientation == 'E')
				{
					game->player->dir_x = 1;
					game->player->dir_y = 0;
					game->player->plane_x = 0;
					game->player->plane_y = 0.66;
				}
				else if (orientation == 'W')
				{
					game->player->dir_x = -1;
					game->player->dir_y = 0;
					game->player->plane_x = 0;
					game->player->plane_y = -0.66;
				}

				game->map->map_data[row][col] = '0'; // Replace the player start position with '0'
				printf("Player initialized at (%f, %f)\n", game->player->x, game->player->y);
				printf("Direction vector: (%f, %f)\n", game->player->dir_x, game->player->dir_y);
				printf("Plane vector: (%f, %f)\n", game->player->plane_x, game->player->plane_y);
				return;
			}
			col++;
		}
		row++;
	}
}

