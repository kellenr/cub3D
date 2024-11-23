/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:19 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/23 02:23:52 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* int	main(int argc, char **argv)
{
	t_game	game;

	check_argc(argc, argv);
	parse_file(&game, argv[1]);
	print_map(game.map);
	ft_printf("🎮 Starting the game with map: %s\n", argv[1]);
	init_mlx(&game);
	// start_intro(&game);
	// // raycast(&game);
	// // mlx_put_image_to_window(game.mlx->mlx, game.mlx->win, game.imgs->img, 0, 0);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
} */

// int	render_frames(void *param)
// {
// 	t_game	*game;
// 	int		x;
// 	int		y;

// 	game = (t_game *)param;
// 	if (!game)
// 		return (0);
// 	handle_movement(game);
// 	memset(game->imgs->pix, 0, W_HEIGHT * game->imgs->ln_len);

// 	// Clear the image buffer by setting it to a background color (e.g., sky blue for ceiling, brown for floor)
// 	for (y = 0; y < W_HEIGHT / 2; y++) // Ceiling
// 	{
// 		for (x = 0; x < W_WIDTH; x++)
// 			my_mlx_pixel_put(game->imgs, x, y, 0x87CEEB); // Sky Blue
// 	}
// 	for (y = W_HEIGHT / 2; y < W_HEIGHT; y++) // Floor
// 	{
// 		for (x = 0; x < W_WIDTH; x++)
// 			my_mlx_pixel_put(game->imgs, x, y, 0x8B4513); // Saddle Brown
// 	}

// 	// Existing Raycasting and Wall Rendering Logic
// 	x = 0;
// 	while (x < W_WIDTH)
// 	{
// 		t_ray	ray;
// 		int		color;

// 		init_ray(&ray, game, x);
// 		calculate_step_and_side_dist(&ray, game);
// 		perform_dda(&ray, game);
// 		calculate_wall_height(&ray, game->player);

// 		// Simple color differentiation
// 		if (ray.side == 1)
// 			color = 0x800080; // purple for horizontal walls
// 		else
// 			color = 0xFFC0CB; // pink for vertical walls

// 		// Draw the vertical line for the wall
// 		int	y_start = ray.draw_start;
// 		int	y_end = ray.draw_end;
// 		for (y = y_start; y <= y_end; y++)
// 		{
// 			my_mlx_pixel_put(game->imgs, x, y, color);
// 		}

// 		x++;
// 	}
// 	// render_minimap(game);
// 	// After rendering, put the image to the window
// 	mlx_put_image_to_window(game->mlx, game->win, game->imgs->img, 0, 0);
// 	return (0);
// }


int	main(int argc, char **argv)
{
	t_game	game;

	initialize_game(&game);
	check_argc(argc, argv);
	parse_file(&game, argv[1]);
	art(argv[1]);
	// print_map(game.map);
	init_mlx(&game);
	game.imgs = init_imgs(&game);
	ft_events(&game);
	// mlx_loop_hook(game.mlx, &render_frames, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
}
