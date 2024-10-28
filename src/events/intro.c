/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:17:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/24 18:02:36 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	display_intro(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	mlx_string_put(game->mlx->mlx, game->mlx->win, 400, 300, 0xFFFFFF, "Welcome to the Game!");
	mlx_string_put(game->mlx->mlx, game->mlx->win, 400, 350, 0xFFFFFF, "Press Enter to continue...");
}


void	start_intro(t_game *game)
{
	display_intro(game);
}

