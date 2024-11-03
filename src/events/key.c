/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:11:59 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/30 14:57:07 by keramos-         ###   ########.fr       */
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

/*
int	handle_keypress(int key, t_game *game)
{
	if (key == KEY_W)
		move_player_forward(game);
	else if (key == KEY_S)
		move_player_backward(game);
	else if (key == KEY_A)
		rotate_player_left(game);
	else if (key == KEY_D)
		rotate_player_right(game);
	else if (key == KEY_ESC)
		exit_game(game);
	return (0);
} */
