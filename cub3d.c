/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:19 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/29 13:11:04 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_textures(t_txt *txt)
{
	printf("North texture: %s\n", txt->north ? txt->north : "Not set");
	printf("South texture: %s\n", txt->south ? txt->south : "Not set");
	printf("West texture: %s\n", txt->west ? txt->west : "Not set");
	printf("East texture: %s\n", txt->east ? txt->east : "Not set");

	// Print floor and ceiling colors in RGB format if they are set
	if (txt->floor_color >= 0)
		printf("Floor color: #%06X\n", txt->floor_color);
	else
		printf("Floor color: Not set\n");

	if (txt->ceiling_color >= 0)
		printf("Ceiling color: #%06X\n", txt->ceiling_color);
	else
		printf("Ceiling color: Not set\n");
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_data[i])
	{
		ft_printf("%s\n", map->map_data[i]); // Using ft_printf from libft to print the map lines
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_game	game;


	check_argc(argc, argv);
	parse_file(&game, argv[1]);
	init_game(&game);
	print_map(game.map);
	ft_printf("🎮 Starting the game with map: %s\n", argv[1]);
	init_mlx(&game);
	start_intro(&game);
	mlx_loop(game.mlx->mlx);
	free(game.mlx);
	return (0);
}
