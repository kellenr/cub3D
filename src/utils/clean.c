/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:37:19 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/24 22:45:04 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_init(t_game *game)
{
	game->mlx = NULL;  // Initialize the mlx pointer
	game->win = NULL;  // Initialize the window pointer
	game->map->map_data = NULL;  // Initialize map
	game->imgs->img = NULL;  // Initialize image structure
	game->imgs->pix = NULL;  // Initialize pixel data
	game->txt->north = NULL;  // Initialize texture structure
	game->txt->south = NULL;  // Initialize texture structure
	game->txt->west = NULL;  // Initialize texture structure
	game->txt->east = NULL;  // Initialize texture structure
	game->player = NULL;  // Initialize player
}

// int	close_handler(t_game *game)
// {
// 	mlx_destroy_image(game->mlx, game->imgs->img);
// 	mlx_destroy_window(game->mlx, game->win);
// 	mlx_destroy_display(game->mlx);
// 	free(game->mlx);
// 	exit(EXIT_SUCCESS);
// 	// return (0);
// }
int	close_handler(t_game *game)
{
	printf("Closing the game and cleaning up resources.\n");
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx); // For Linux; omit if on macOS
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

/* void	clean_free(t_game *game)
{
	if (game->map)
	{
		if (game->map->map_data)
		{
			for (int i = 0; i < game->map->height; i++)
				free(game->map->map_data[i]);
			free(game->map->map_data);
		}
		free(game->map);
	}
	if (game->mlx)
	{
		if (game->mlx->bg_image)
			mlx_destroy_image(game->mlx->mlx, game->mlx->bg_image);
		if (game->mlx->win)
			mlx_destroy_window(game->mlx->mlx, game->mlx->win);
		if (game->mlx->mlx)
			mlx_destroy_display(game->mlx->mlx);
		free(game->mlx->mlx);
		free(game->mlx);
	}
	if (game->txt)
	{
		if (game->txt->north)
			free(game->txt->north);
		if (game->txt->south)
			free(game->txt->south);
		if (game->txt->west)
			free(game->txt->west);
		if (game->txt->east)
			free(game->txt->east);
		if (game->txt->sprite)
			free(game->txt->sprite);
		free(game->txt);
	}
	if (game->imgs)
	{
		if (game->imgs->img)
			mlx_destroy_image(game->mlx->mlx, game->imgs->img);
		free(game->imgs);
	}
	exit(EXIT_FAILURE);

} */
