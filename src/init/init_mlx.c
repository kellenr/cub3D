/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:28:23 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/23 02:00:02 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	load_background(t_game *game, char *path)
// {
// 	int	width;
// 	int	height;

// 	game->mlx->bg_image = mlx_xpm_file_to_image(game->mlx->mlx, path, &width, &height);
// 	if (!game->mlx->bg_image)
// 	{
// 		fprintf(stderr, "Error: Failed to load background image from %s\n", path);
// 		// Handle the error appropriately, possibly exiting the program
// 		exit(EXIT_FAILURE);
// 	}
// }

/*
 * Function to initialize the MLX connection and window
 * Exits on failure
 */
void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Failed to initialize MLX");
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx); // For Linux; omit if on macOS
		free(game->mlx);
		ft_error("Failed to create window");
	}
}

/*
 * Function to initialize the images structure
 * Returns a pointer to t_imgs on success, exits on failure
 */
t_imgs	*init_imgs(t_game *game)
{
	t_imgs	*imgs;

	imgs = malloc(sizeof(t_imgs));
	if (!imgs)
		ft_error("Failed to allocate memory for images");
	imgs->img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	if (!imgs->img)
	{
		free(imgs);
		ft_error("Failed to create image");
	}
	imgs->pix = mlx_get_data_addr(imgs->img, &imgs->bitp, &imgs->ln_len, \
				&imgs->endian);
	return (imgs);
}

void	init_txt_path(t_game *game, t_imgs *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &game->txt->size_w, &game->txt->size_h);
	if (!img->img)
		ft_error("Failed to load texture");
	img->pix = mlx_get_data_addr(img->img, &img->bitp, &img->ln_len, &img->endian);
	return ;
}
