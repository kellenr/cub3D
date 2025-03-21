/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:33:03 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:24:46 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_adjacent_to_space(t_game *game, int y, int x)
{
	if (y <= 0 || x >= (int)ft_strlen(game->map->map_data[y - 1]) || \
		game->map->map_data[y - 1][x] == ' ')
		return (1);
	if (y >= game->map->height - 1 || x >= \
		(int)ft_strlen(game->map->map_data[y + 1]) || \
		game->map->map_data[y + 1][x] == ' ')
		return (1);
	if (x <= 0 || game->map->map_data[y][x - 1] == ' ')
		return (1);
	if (x >= (int)ft_strlen(game->map->map_data[y]) - 1 || \
		game->map->map_data[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	check_row_enclosed(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map->map_data[i][j] && game->map->map_data[i][j] == ' ')
		j++;
	if (game->map->map_data[i][j] && game->map->map_data[i][j] != '1')
		return (0);
	j = ft_strlen(game->map->map_data[i]) - 1;
	while (j >= 0 && game->map->map_data[i][j] == ' ')
		j--;
	if (j >= 0 && game->map->map_data[i][j] != '1')
		return (0);
	return (1);
}

int	check_boundaries(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		if (i == 0 || i == game->map->height - 1)
		{
			j = 0;
			while (game->map->map_data[i][j])
			{
				if (game->map->map_data[i][j] != '1' && \
					game->map->map_data[i][j] != ' ')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	check_spaces_adjacent(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->map_data[i]))
		{
			if (game->map->map_data[i][j] == '0' ||
				ft_strchr("NSEW", game->map->map_data[i][j]))
			{
				if (is_adjacent_to_space(game, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_layout(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (game->map->height <= 3 && ft_strlen(game->map->map_data[i]) <= 3)
			clean_error(game, "Map is too small");
		if (!check_row_enclosed(game, i))
			return (0);
		i++;
	}
	if (!check_boundaries(game))
		return (0);
	if (!check_spaces_adjacent(game))
		return (0);
	return (1);
}
