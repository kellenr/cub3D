/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:26:57 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 20:37:34 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->mlx)
		{
			if (game->mlx->win)
				mlx_destroy_window(game->mlx->mlx, game->mlx->win);
			free(game->mlx);
		}
		if (game->imgs)
			free(game->imgs);
		if (game->map)
			free(game->map);
		free(game);
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->map_data)
	{
		while (map->map_data[i])
		{
			free(map->map_data[i]);
			map->map_data[i] = NULL;
			i++;
		}
		free(map->map_data);
	}
}

	/* if (game->mlx->win)
	{
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
		mlx_destroy_display(game->mlx->mlx);
		free(game->mlx->mlx);
	}
	if (game->imgs)
	{
		mlx_destroy_image(game->mlx->mlx, game->imgs->img);
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
		mlx_destroy_display(game->mlx->mlx);
		free(game->imgs);
	}
	if(game->mlx)
	{
		mlx_destroy_display(game->mlx->mlx);
		free(game->mlx);
	} */
