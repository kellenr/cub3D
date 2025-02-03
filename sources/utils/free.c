/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:26:57 by keramos-          #+#    #+#             */
/*   Updated: 2025/02/03 19:58:57 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		map->map_data = NULL;
	}
	free(map);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_textures_imgs(t_txt *txt, void *mlx)
{
	if (!txt || !mlx)
		return;
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
}

void	free_mlx(t_game *game)
{

	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->imgs.img)
	{
		mlx_destroy_image(game->mlx, game->imgs.img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
// void	free_game(t_game *game)
// {
// 	if (!game)
// 		return;
// 	// Free each component
// 	free_map(game->map);
// 	free_texture(game->txt);
// 	free_player(game->player);
// }
