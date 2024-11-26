/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_txt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:59:17 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/25 02:51:24 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pix(t_game *game)
{
	int	i;

	i = 0;
	if (game->txt_pix)
		free(game->txt_pix);
	game->txt_pix = ft_calloc(W_HEIGHT + 1, sizeof(int *));
	if (!game->txt_pix)
		ft_error("Failed to allocate memory for txt_pix");
	while (i < W_HEIGHT)
	{
		game->txt_pix[i] = ft_calloc(W_WIDTH + 1, sizeof(int));
		if (!game->txt_pix[i])
			ft_error("Failed to allocate memory for txt_pix[i]");
		i++;
	}
}

void	get_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			game->txt->id = EAST;
		else
			game->txt->id = WEST;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			game->txt->id = SOUTH;
		else
			game->txt->id = NORTH;
	}
}

void	draw_line(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	color;

	get_wall(game, ray);
	ray->tex_x = (int)(ray->wall_x * (double)game->txt->size_w);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1 && ray->ray_dir_y > 0)) // or ><
		ray->tex_x = game->txt->size_w - ray->tex_x - 1;
	ray->step = 1.0 * game->txt->size_h / ray->line_height;
	ray->tex_pos = (ray->draw_start - W_HEIGHT / 2 + ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (game->txt->size_h - 1);
		ray->tex_pos += ray->step;
		color = game->txt_data[game->txt->id][game->txt->size_w * ray->tex_y + ray->tex_x];
		if (game->txt->id == NORTH || game->txt->id == EAST)
			color = (color >> 1);
		if (color > 0)
		{
			game->txt_pix[y][x] = color;
		}
		y++;
	}
}
