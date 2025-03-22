/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:24 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:35:29 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function that uses the player direction to initialize the player's direction
 * and plane vectors
 */
void	init_player_no_so(t_player *player)
{
	if (player->di == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (player->di == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

void	init_player_ea_we(t_player *player)
{
	if (player->di == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (player->di == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else
		return ;
}

/*
 * Function to initialize the player structure
 * Returns a pointer to the player structure
 */
void	initialize_player(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < (int)ft_strlen(game->map->map_data[row]))
		{
			game->player.di = game->map->map_data[row][col];
			if (game->player.di == 'N' || game->player.di == 'S' || \
				game->player.di == 'E' || game->player.di == 'W')
			{
				game->player.x = col + 0.5;
				game->player.y = row + 0.5;
				init_player_no_so(&game->player);
				init_player_ea_we(&game->player);
				game->map->map_data[row][col] = '0';
				return ;
			}
			col++;
		}
		row++;
	}
}
