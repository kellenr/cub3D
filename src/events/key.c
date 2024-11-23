/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:11:59 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/22 17:01:29 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_keys(t_keys *keys)
{
	keys->forward = 0;
	keys->backward = 0;
	keys->left = 0;
	keys->right = 0;
	keys->rotate_left = 0;
	keys->rotate_right = 0;
}

int	key_handler(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->keys;
	if (keycode == XK_w)
		keys->forward = 1;
	else if (keycode == XK_s)
		keys->backward = 1;
	else if (keycode == XK_a)
		keys->left = 1;
	else if (keycode == XK_d)
		keys->right = 1;
	else if (keycode == XK_Left)
		keys->rotate_left = 1;
	else if (keycode == XK_Right)
		keys->rotate_right = 1;
	if (keycode == XK_Escape)
		close_handler(game);
	if(keycode == XK_KP_Enter || keycode == XK_Return)
		mlx_clear_window(game->mlx, game->win);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	t_keys	*keys;

	keys = &game->keys;
	if (keycode == XK_w)
		keys->forward = 0;
	else if (keycode == XK_s)
		keys->backward = 0;
	else if (keycode == XK_a)
		keys->left = 0;
	else if (keycode == XK_d)
		keys->right = 0;
	else if (keycode == XK_Left)
		keys->rotate_left = 0;
	else if (keycode == XK_Right)
		keys->rotate_right = 0;
	return (0);
}

void	ft_events(t_game *game)
{
	init_keys(&game->keys);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_handler, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
	// mlx_hook(fc->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fc);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, \
				close_handler, game);
}
