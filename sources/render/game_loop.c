/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:12:31 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/27 19:42:38 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			draw_pixel(&game->imgs, x, y, game->txt.ceiling_color);
			x++;
		}
		y++;
	}
	y = W_HEIGHT / 2;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			draw_pixel(&game->imgs, x, y, game->txt.floor_color);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(game->mlx, game->win, game->imgs.img, 0, 0);
}

int	start_game(t_game *game)
{
	handle_movement(game);
	raycast(game);
	return (0);
}
