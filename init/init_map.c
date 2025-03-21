/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:24:00 by kellen            #+#    #+#             */
/*   Updated: 2025/03/19 20:47:41 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to initialize the player structure
 * Returns a pointer to t_player on success, exits on failure
 */
void	init_player(t_player *player)
{
	player->x = 0.0f;
	player->y = 0.0f;
	player->dir_x = 0.0f;
	player->dir_y = 0.0f;
	player->plane_x = 0.0f;
	player->plane_y = 0.0f;
	player->angle = 0.0f;
	player->di = 'N';
}
