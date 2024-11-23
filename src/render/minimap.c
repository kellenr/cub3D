/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:24:34 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/22 20:07:29 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	set_minimap_tile_pixels(t_minimap *minimap, int x, int y, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < minimap->tile_size)
// 	{
// 		j = 0;
// 		while (j < minimap->tile_size)
// 		{
// 			my_mlx_pixel_put(minimap->imgs, x + j, i + y, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	draw_minimap_tile(t_minimap *minimap, int x, int y)
// {
// 	if (minimap->map[y][x] == 'P')
// 		set_minimap_tile_pixels(minimap, x * minimap->tile_size,
// 			y * minimap->tile_size, COLOR_PLAYER);
// 	else if (minimap->map[y][x] == '1')
// 		set_minimap_tile_pixels(minimap, x * minimap->tile_size,
// 			y * minimap->tile_size, COLOR_WALL);
// 	else if (minimap->map[y][x] == '0')
// 		set_minimap_tile_pixels(minimap, x * minimap->tile_size,
// 			y * minimap->tile_size, COLOR_FLOOR);
// 	else if (minimap->map[y][x] == ' ')
// 		set_minimap_tile_pixels(minimap, x * minimap->tile_size,
// 			y * minimap->tile_size, COLOR_SPACE);
// }

// static void	set_minimap_border_image_pixels(t_minimap *minimap, int color)
// {
// 	int	size;
// 	int	x;
// 	int	y;

// 	size = MINIMAP_SIZE + minimap->tile_size;
// 	y = 0;
// 	while (y < size)
// 	{
// 		x = 0;
// 		while (x <= size)
// 		{
// 			if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
// 				my_mlx_pixel_put(minimap->imgs, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static void	draw_minimap(t_minimap *minimap)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < minimap->scale)
// 	{
// 		x = 0;
// 		while (x < minimap->scale)
// 		{
// 			if (!minimap->map[y] || !minimap->map[y][x]
// 				|| minimap->map[y][x] == '\0')
// 				break ;
// 			draw_minimap_tile(minimap, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	set_minimap_border_image_pixels(minimap, COLOR_SPACE);
// }

// void	render_minimap_image(t_game *data, t_minimap *minimap)
// {
// 	init_imgs(data);
// 	draw_minimap(minimap);
// 	mlx_put_image_to_window(data->mlx, data->win, data->imgs->img,
// 		minimap->tile_size, W_HEIGHT
// 		- (MINIMAP_SIZE + (minimap->tile_size * 2)));
// 	mlx_destroy_image(data->mlx, data->imgs->img);
// }
// static int	get_mmap_offset(t_minimap *minimap, int mapsize, int pos)
// {
// 	if (pos > minimap->view && mapsize - pos > minimap->view + 1)
// 		return (pos - minimap->view);
// 	if (pos > minimap->view && mapsize - pos <= minimap->view + 1)
// 		return (mapsize - minimap->scale);
// 	return (0);
// }

// static bool	is_valid_map_coord(int coord, int size)
// {
// 	if (coord < size)
// 		return (true);
// 	return (false);
// }

// static char	*add_minimap_line(t_game *d, t_minimap *m, int y)
// {
// 	char	*line;
// 	int		x;

// 	line = ft_calloc(m->scale + 1, sizeof * line);
// 	if (!line)
// 		return (NULL);
// 	x = 0;
// 	while (x < m->scale && x < d->map->width)
// 	{
// 		if (!is_valid_map_coord(y + m->y, d->map->height)
// 			|| !is_valid_map_coord(x + m->x, d->map->width))
// 			line[x] = '\0';
// 		else if ((int)d->player->x == (x + m->x)
// 			&& (int)d->player->y == (y + m->y))
// 			line[x] = 'P';
// 		// else if (d->map[y + m->y][x + m->x] == '1')
// 		// 	line[x] = '1';
// 		// else if (d->map[y + m->y][x + m->x] == '0')
// 		// 	line[x] = '0';
// 		else
// 			line[x] = '\0';
// 		x++;
// 	}
// 	return (line);
// }

// static char	**generate_minimap(t_game *data, t_minimap *minimap)
// {
// 	char	**mmap;
// 	int		y;

// 	mmap = ft_calloc(minimap->scale + 1, sizeof * mmap);
// 	if (!mmap)
// 		return (NULL);
// 	y = 0;
// 	while (y < minimap->scale && y < data->map->height)
// 	{
// 		mmap[y] = add_minimap_line(data, minimap, y);
// 		if (!mmap[y])
// 		{
// 			return (NULL);
// 		}
// 		y++;
// 	}
// 	return (mmap);
// }

// void	render_minimap(t_game *data)
// {
// 	t_minimap	minimap;

// 	minimap.map = NULL;
// 	minimap.imgs = data->imgs;
// 	minimap.view = MINIMAP_SCALE;
// 	minimap.scale = (2 * minimap.view) + 1;
// 	minimap.tile_size = MINIMAP_SIZE / (2 * minimap.view);
// 	minimap.x = get_mmap_offset(&minimap,
// 			data->map->width, (int)data->player->x);
// 	minimap.y = get_mmap_offset(&minimap,
// 			data->map->height, (int)data->player->y);
// 	minimap.map = generate_minimap(data, &minimap);
// 	render_minimap_image(data, &minimap);
// }
