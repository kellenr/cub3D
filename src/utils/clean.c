/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:37:19 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/25 22:53:31 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_init(t_game *game)
{
	game->mlx = NULL;  // Initialize the mlx pointer
	game->map = NULL;  // Initialize map
	game->txt = NULL;  // Initialize texture structure
}

int	close_handler(t_game *game)
{
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
// {
// 	mlx_destroy_image(fc->mlx, fc->img.img);
// 	mlx_destroy_window(fc->mlx, fc->mlx_window);
// 	mlx_destroy_display(fc->mlx);
// 	free(fc->mlx);
// 	free(fc->palette);
// 	exit(EXIT_SUCCESS);
// }
/* {
	fc->mlx = NULL;
	fc->mlx_window = NULL;
	fc->img.img = NULL;
	fc->img.pix = NULL;
	fc->palette = NULL;
	fc->color_p = -1;
	fc->set = -1;
	fc->r.min = 0;
	fc->r.max = 0;
	fc->i.min = 0;
	fc->i.max = 0;
	fc->j.r = 0;
	fc->j.i = 0;
	fc->color = 0;
} */
