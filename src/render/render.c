/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:46:12 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/25 02:53:53 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	dst = img->pix + (y * img->ln_len + x * (img->bitp / 8));
	*(unsigned int*)dst = color;
}

void	frame_img_pix(t_game *game, t_imgs *img, int x, int y)
{
	if (game->txt_pix[y][x] != 0)
		my_mlx_pixel_put(img, x, y, game->txt_pix[y][x]);
	if (y < W_HEIGHT / 2)
		my_mlx_pixel_put(img, x, y, game->txt->ceiling_color);
	else if (y < W_HEIGHT - 1)
		my_mlx_pixel_put(img, x, y, game->txt->floor_color);
}

void	render_frame(t_game *game)
{
	int	x;
	int	y;

	init_imgs(game);
	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			frame_img_pix(game, game->imgs, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->imgs->img, 0, 0);
	mlx_destroy_image(game->mlx, game->imgs->img);
}

int	render(t_game *game)
{
	init_pix(game);
	handle_movement(game);
	// memset(game->imgs->pix, 0, W_HEIGHT * game->imgs->ln_len);
	raycast(game);
	render_frame(game);
	return (0);
}
