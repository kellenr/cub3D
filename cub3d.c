/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:11 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 17:01:19 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_argc(argc, argv);
	game = init_game();
	init_window(game);
	ft_printf("🎮 Starting the game with map: %s\n", argv[1]);
	ft_events(game);
	mlx_loop(game->mlx->mlx);
	free_game(game);
	return (0);
}
