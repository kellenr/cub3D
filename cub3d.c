/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:11 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/17 15:33:23 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_game	*game;

	check_argc(argc, argv);
	game = init_game(argv[1]);
	print_map(game->map);
	init_window(game);
	ft_printf("🎮 Starting the game with map: %s\n", argv[1]);
	ft_events(game);
	mlx_loop(game->mlx->mlx);
	free_game(game);
	return (0);
}
