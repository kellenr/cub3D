/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:42:50 by keramos-          #+#    #+#             */
/*   Updated: 2025/01/29 20:44:25 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to initialize the images structure
 * Returns a pointer to t_imgs on success, exits on failure
 */
void	init_txt(t_txt *txt)
{
	txt->north = NULL;
	txt->south = NULL;
	txt->west = NULL;
	txt->east = NULL;
	txt->sprite = NULL;
	txt->door = NULL;
	txt->floor_color = -1;
	txt->ceiling_color = -1;
	txt->size = 64;
	txt->step = 0;
	txt->tex_pos = 0;
	txt->x = 0;
	txt->y = 0;

}

void	check_texture_data(t_imgs *texture, const char *name)
{
	printf("Checking texture: %s\n", name);
	printf("Image pointer: %p\n", texture->img);
	printf("Pixel data pointer: %p\n", texture->pix);
	printf("Bits per pixel: %d\n", texture->bitp);
	printf("Line length: %d\n", texture->ln_len);
	printf("Endian: %d\n", texture->endian);

	// Print the color of the first pixel
	if (texture->pix)
	{
		unsigned int color = *(unsigned int *)(texture->pix);
		printf("First pixel color: %#X\n", color);
	}
	else
	{
		printf("No pixel data available.\n");
	}
}

// void	init_textures(t_txt *txt)
// {
// 	txt->textures[NORTH] = &txt->no;
// 	txt->textures[SOUTH] = &txt->so;
// 	txt->textures[WEST] = &txt->we;
// 	txt->textures[EAST] = &txt->ea;
// }


void	load_txt(t_game *game)
{
	init_txt_path(game, &game->txt.no, game->txt.north);
	init_txt_path(game, &game->txt.so, game->txt.south);
	init_txt_path(game, &game->txt.we, game->txt.west);
	init_txt_path(game, &game->txt.ea, game->txt.east);
	// init_txt_path(game, &game->txt.no, game->txt.north);
	// check_texture_data(&game->txt.no, "North Wall");

	// init_txt_path(game, &game->txt.so, game->txt.south);
	// check_texture_data(&game->txt.so, "South Wall");

	// init_txt_path(game, &game->txt.we, game->txt.west);
	// check_texture_data(&game->txt.we, "West Wall");

	// init_txt_path(game, &game->txt.ea, game->txt.east);
	// check_texture_data(&game->txt.ea, "East Wall");
	// init_textures(&game->txt);
}
