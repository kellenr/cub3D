/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:44:18 by alexa             #+#    #+#             */
/*   Updated: 2025/02/03 19:58:15 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->map_data[i]);
		i++;
	}
}

void	print_texture(t_txt *txt)
{
	ft_printf("NO: %s\n", txt->north);
	ft_printf("SO: %s\n", txt->south);
	ft_printf("WE: %s\n", txt->west);
	ft_printf("EA: %s\n", txt->east);
	ft_printf("S: %s\n", txt->sprite);
	ft_printf("F: %d\n", txt->floor_color);
	ft_printf("C: %d\n", txt->ceiling_color);
} */

int	main(int argc, char **argv)
{
	t_game	game;

	initialize_game(&game);
	check_argc(argc, argv);
	parse_file(&game, argv[1]);
	art(argv[1]);
	init_mlx(&game);
	init_imgs(&game);
	load_txt(&game);
	ft_events(&game);
	mlx_loop_hook(game.mlx, &start_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
