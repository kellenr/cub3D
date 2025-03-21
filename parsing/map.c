/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:42:59 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:10:27 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char c)
{
	if (c == '\n' || c == ' ' || c == '0' || c == '1' || \
		c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		return (1);
	}
	if (BONUS)
	{
		if (c == 'D' || c == 'X')
			return (1);
	}
	return (0);
}

int	is_map(t_game *game)
{
	int	ln;

	if (is_valid_line(game))
	{
		ln = ft_strlen(game->n_line);
		if (ln > game->map->width)
			game->map->width = ln;
		game->map->height++;
		return (1);
	}
	return (0);
}

int	is_valid_line(t_game *game)
{
	int	i;

	i = 0;
	if (is_empty_line(game->n_line))
	{
		if (game->start)
			if (game->line >= (game->map->height + game->s_map))
				return (0);
		return (0);
	}
	while (game->n_line[i])
	{
		if (!is_valid_char(game->n_line[i]))
		{
			if (game->start)
				clean_error(game, "Invalid element in map.");
			return (0);
		}
		i++;
	}
	if (!game->start)
	{
		game->start = 1;
		game->s_map = game->line;
	}
	return (1);
}

int	parse_map(t_game *game)
{
	int	i;

	i = 0;
	game->map->map_data = calloc((game->map->height + 1), sizeof(char *));
	if (!game->map->map_data)
		clean_error(game, "Error: Memory allocation failed for map");
	while (game->n_line && i < game->map->height)
	{
		if (valid_map_save(game))
		{
			save_map(game, i);
			i++;
		}
		free(game->n_line);
		game->n_line = get_next_line(game->fd);
		game->line++;
	}
	game->map->map_data[i] = NULL;
	validate_map(game);
	return (1);
}

void	save_map(t_game *game, int i)
{
	int	len;

	len = ft_strlen(game->n_line);
	if (game->n_line[len - 1] == '\n')
		game->n_line[len - 1] = '\0';
	game->map->map_data[i] = ft_strdup(game->n_line);
	if (!game->map->map_data[i])
		clean_error(game, "Memory allocation failed for map line");
	(i)++;
}
