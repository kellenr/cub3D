/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:37:19 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:22:37 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_imgs(t_imgs *imgs)
{
	if (!imgs)
		return ;
	imgs->img = NULL;
	imgs->pix = NULL;
	imgs->bitp = 0;
	imgs->ln_len = 0;
	imgs->endian = 0;
}

int	close_handler(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->txt.i.img || game->txt.no.img || game->txt.so.img || \
		game->txt.we.img || game->txt.ea.img || game->txt.d.img)
		free_textures_imgs(&game->txt, game->mlx);
	if (game->imgs.img)
	{
		mlx_destroy_image(game->mlx, game->imgs.img);
		game->imgs.img = NULL;
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(EXIT_SUCCESS);
}

void	free_mlx(t_game *game)
{
	if (game->imgs.img)
	{
		mlx_destroy_image(game->mlx, game->imgs.img);
		game->imgs.img = NULL;
	}
	free_textures_imgs(&game->txt, game->mlx);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}

void	free_textures_imgs(t_txt *txt, void *mlx)
{
	if (!txt || !mlx)
		return ;
	if (txt->no.img)
	{
		mlx_destroy_image(mlx, txt->no.img);
		free(txt->north);
		txt->no.img = NULL;
	}
	if (txt->so.img)
	{
		mlx_destroy_image(mlx, txt->so.img);
		free(txt->south);
		txt->so.img = NULL;
	}
	if (txt->we.img)
	{
		mlx_destroy_image(mlx, txt->we.img);
		free(txt->west);
		txt->we.img = NULL;
	}
	if (txt->ea.img)
	{
		mlx_destroy_image(mlx, txt->ea.img);
		free(txt->east);
		txt->ea.img = NULL;
	}
	if (txt->door && txt->d.img)
	{
		mlx_destroy_image(mlx, txt->d.img);
		txt->d.img = NULL;
	}
	if (txt->i.img)
	{
		mlx_destroy_image(mlx, txt->i.img);
		txt->i.img = NULL;
	}
}
