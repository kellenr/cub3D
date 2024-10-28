/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:28:23 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/24 16:26:05 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	if (!game->mlx)
		ft_error("MLX structure is not allocated");
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
		ft_error("Failed to initialize MLX");
	game->mlx->win = mlx_new_window(game->mlx->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!game->mlx->win)
		ft_error("Failed to create window");
	ft_events(game);
}

/*
//window_init:
//Creates a new MLX instance, a new window and populates
//the fractol data structure with default values.
void	window_init(t_fractol *fc)
{
	fc->mlx = mlx_init();
	if (!fc->mlx)
	{
		clean_free(fc);
		ft_error();
	}
	fc->mlx_window = mlx_new_window(fc->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fc->mlx_window)
	{
		clean_free(fc);
		ft_error();
	}
	ft_events(fc);
	ft_color(fc);
} */
