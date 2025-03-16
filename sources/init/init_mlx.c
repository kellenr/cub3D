/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:28:23 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 01:37:00 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to initialize the MLX connection and window
 * Exits on failure
 */
void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_error("Failed to initialize MLX");
	}
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!game->win)
	{
		ft_error("Failed to create window");
	}
}

/*
 * Function to initialize the images structure
 * Returns a pointer to t_imgs on success, exits on failure
 */
void	init_imgs(t_game *game)
{
	game->imgs.img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	if (!game->imgs.img)
	{
		free_mlx(game);
		ft_error("Failed to create image");
	}
	game->imgs.pix = mlx_get_data_addr(game->imgs.img, &game->imgs.bitp, &game->imgs.ln_len, \
				&game->imgs.endian);
	if (!game->imgs.pix)
	{
		ft_error("Failed to get image data");
	}
	return ;
}

void	init_txt_path(t_game *game, t_imgs *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &game->txt.size, &game->txt.size);
	if (!img->img)
	{
		free_mlx(game);
		ft_error("Failed to load texture");
	}
	img->pix = mlx_get_data_addr(img->img, &img->bitp, &img->ln_len, &img->endian);
	return ;
}
