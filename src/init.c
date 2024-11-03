/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:32:04 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 20:39:58 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_game *game)
{
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
	{
		free_game(game);
		ft_error("Failed to initialize mlx");
	}
	// game->mlx->win = mlx_new_window(game->mlx->mlx, W_WIDTH, W_HEIGHT, "cub3D");
	game->mlx->win = mlx_new_window(game->mlx->mlx, game->map->width,
			game->map->height, "cub3D");
	if (!game->mlx->win)
	{
		free_game(game);
		ft_error("Failed to create window");
	}
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Failed to allocate memory for game");
	game->mlx = init_mlx(game);
	game->imgs = init_imgs(game);
	game->map = init_map(game);
	return (game);
}

t_mlx	*init_mlx(t_game *game)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		free(game);
		ft_error("Failed to allocate memory for mlx");
	}
	return (mlx);
}

t_imgs	*init_imgs(t_game *game)
{
	t_imgs	*imgs;

	imgs = malloc(sizeof(t_imgs));
	if (!imgs)
	{
		free(game->mlx);
		free(game);
		ft_error("Failed to allocate memory for images");
	}
	return (imgs);
}

t_map	*init_map(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		free(game->imgs);
		free(game->mlx);
		free(game);
		ft_error("Failed to allocate memory for map");
	}
	return (map);
}
