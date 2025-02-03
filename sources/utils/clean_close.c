/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:37:19 by keramos-          #+#    #+#             */
/*   Updated: 2025/02/03 19:59:26 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_imgs(t_imgs *imgs)
{
	imgs->img = NULL;
	imgs->pix = NULL;
	imgs->bitp = 0;
	imgs->ln_len = 0;
	imgs->endian = 0;
}

int	close_handler(t_game *game)
{
	free_map(game->map);
	free_textures_imgs(&game->txt, game->mlx);
	mlx_destroy_image(game->mlx, game->imgs.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

// {
// 	mlx_destroy_image(game->mlx, game->imgs->img);
// 	mlx_destroy_window(game->mlx, game->win);
// 	mlx_destroy_display(game->mlx);
// 	free(game->mlx);
// 	exit(EXIT_SUCCESS);
// 	// return (0);
// }
// int	close_handler(t_game *game)
// {
// 	printf("Closing the game and cleaning up resources.\n");

// 	if (game->imgs)
// 	{
// 		if (game->imgs->img)
// 			mlx_destroy_image(game->mlx, game->imgs->img);
// 		free(game->imgs);
// 	}
// 	if (game->win)
// 		mlx_destroy_window(game->mlx, game->win);
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx); // For Linux; omit if on macOS
// 		free(game->mlx);
// 	}
// 	// Free other allocated resources (map, textures, player)
// 	// Example:
// 	// free_map(game.map);
// 	// free_player(game.player);
// 	// free_txt(game.txt);

// 	exit(EXIT_SUCCESS);
// 	return (0);
// }
