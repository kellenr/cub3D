/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:11:59 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/24 16:36:10 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_handler(game);
	if(keycode == XK_KP_Enter || keycode == XK_Return)
	{
		mlx_clear_window(game->mlx->mlx, game->mlx->win);
	}
	return (0);
}

void	ft_events(t_game *game)
{
	mlx_hook(game->mlx->win, KeyPress, KeyPressMask, key_handler, game);
	// mlx_hook(fc->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fc);
	mlx_hook(game->mlx->win, DestroyNotify, StructureNotifyMask, \
				close_handler, game);
}
