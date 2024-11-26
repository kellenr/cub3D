/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:19 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/25 00:49:27 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* int	main(int argc, char **argv)
{
	t_game	game;

	check_argc(argc, argv);
	parse_file(&game, argv[1]);
	print_map(game.map);
	init_mlx(&game);
	// start_intro(&game);
	// // mlx_put_image_to_window(game.mlx->mlx, game.mlx->win, game.imgs->img, 0, 0);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
} */
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

	initialize_game(&game);
	check_argc(argc, argv);
	parse_file(&game, argv[1]);
	art(argv[1]);
	// print_map(game.map);
	init_mlx(&game);
	load_textures(&game);
	ft_events(&game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_loop(game.mlx);
	printf("Game ended\n");
	free(game.mlx);
	return (0);
}
