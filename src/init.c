/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:32:04 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/17 16:00:55 by keramos-         ###   ########.fr       */
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

t_game	*init_game(const char *map_file)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Failed to allocate memory for game");
	game->mlx = init_mlx(game);
	game->imgs = init_imgs(game);
	game->map = init_map(game, map_file);
	if (!is_map_enclosed(game->map))
		ft_error("The map is not enclosed by walls!");
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

t_map	*init_map(t_game *game, const char *map_file)
{
	t_map	*map;
	int		i;

	(void)game;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_error("Failed to allocate memory for map");
		return (NULL);
	}
	map->map_data = load_map(map_file);
	i = 0;
	map->height = 0;
	map->width = 0;
	while (map->map_data[i])
	{
		if (ft_strlen(map->map_data[i]) > (size_t)map->width)
			map->width = ft_strlen(map->map_data[i]);
		map->height++;
		i++;
	}
	ft_printf("Map width: %d\n", map->width);
	ft_printf("Map height: %d\n", map->height);
	return (map);
}
