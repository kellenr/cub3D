/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:47:11 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 16:55:50 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_events(t_game *game)
{
	mlx_hook(game->mlx->win, KeyPress, KeyPressMask, key_handler, game);
	mlx_hook(game->mlx->win, DestroyNotify, StructureNotifyMask, \
				close_handler, game);
}
