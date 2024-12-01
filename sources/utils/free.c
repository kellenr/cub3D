/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:26:57 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/27 15:09:04 by keramos-         ###   ########.fr       */
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
	if (txt->no.img)
		mlx_destroy_image(mlx, txt->no.img);
	if (txt->so.img)
		mlx_destroy_image(mlx, txt->so.img);
	if (txt->we.img)
		mlx_destroy_image(mlx, txt->we.img);
	if (txt->ea.img)
		mlx_destroy_image(mlx, txt->ea.img);
}

// void	free_texture(t_txt *txt)
// {
// 	if (txt)
// 	{
// 		if (txt->north)
// 			free(txt->north);
// 		if (txt->south)
// 			free(txt->south);
// 		if (txt->west)
// 			free(txt->west);
// 		if (txt->east)
// 			free(txt->east);
// 		if (txt->sprite)
// 			free(txt->sprite);
// 		free(txt);
// 	}
// }

// void	free_player(t_player *player)
// {
// 	if (player)
// 		free(player);
// }
// void	free_game(t_game *game)
// {
// 	if (!game)
// 		return;
// 	// Free each component
// 	free_map(game->map);
// 	free_texture(game->txt);
// 	free_player(game->player);
// }


