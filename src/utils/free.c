/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:26:57 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/22 01:06:53 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	free_game(t_game *game)
{
	if (game)
	{
		if (game->imgs)
			free(game->imgs);
		if (game->map)
			free(game->map);
		if (game->mlx)
		{
			if (game->mlx->win)
				mlx_destroy_window(game->mlx->mlx, game->mlx->win);
			free(game->mlx);
		}
		free(game);
	}
} */

void	free_game(t_game *game)
{
	if (!game)
		return;
	if (game->map)
	{
		free(game->map);  // Free the map structure
	}
	// Free MLX window
	if (game->mlx)
	{
		if (game->mlx->win)
			mlx_destroy_window(game->mlx->mlx, game->mlx->win);
		free(game->mlx);
	}
	// Free images (if necessary)
	if (game->imgs)
		free(game->imgs);
	// Finally, free the game structure itself
	free(game);
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

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
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
