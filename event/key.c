/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:11:59 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 02:25:45 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_game_keys(int keycode, t_game *game)
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
	else if (keycode == XK_m)
		game->mini_active = !game->mini_active;
	else if (keycode == XK_space && BONUS)
		toggle_door(game);
	else if (keycode == XK_Escape)
		close_handler(game);
}

int	key_handler(int keycode, t_game *game)
{
	if (game->intro_active)
	{
		if (keycode == XK_Return || keycode == XK_KP_Enter)
		{
			game->intro_active = 0;
			mlx_clear_window(game->mlx, game->win);
		}
		else if (keycode == XK_Escape)
			close_handler(game);
		return (0);
	}
	handle_game_keys(keycode, game);
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
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, \
				close_handler, game);
}
