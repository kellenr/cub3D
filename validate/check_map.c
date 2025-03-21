/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:14 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:24:12 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_map_save(t_game *game)
{
	int	j;

	j = 0;
	while (game->n_line[j])
	{
		if (game->line != (game->map->height + game->s_map) && \
			is_empty_line(game->n_line))
			clean_error(game, "No valid map");
		j++;
	}
	return (1);
}

void	validate_map(t_game *game)
{
	if (!valid_player(game))
		clean_error(game, "No player found in map!");
	if (!valid_layout(game))
		clean_error(game, "The map is not enclosed by walls!");
}

/*
 * Function: is_valid_element
 * -----------------------
 * Checks if the given character is one of the allowed map characters or a
 * space.
 *
 * c: The character to validate.
 *
 * returns: 1 if valid, 0 otherwise.
 */
int	is_valid_element(char c)
{
	if (c == ' ' || c == '0' || c == '1' || \
		c == 'N' || c == 'S' || c == 'E' || \
		c == 'W' )
		return (1);
	if (BONUS)
	{
		if (c == 'D' || c == 'X')
			return (1);
	}
	return (0);
}

int	validate_map_element(char c, int *p_count)
{
	if (!is_valid_element(c))
		return (0);
	if (ft_strchr("NSEW", c))
		(*p_count)++;
	return (1);
}

int	valid_player(t_game *game)
{
	int	i;
	int	j;
	int	p_count;

	i = 0;
	p_count = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (game->map->map_data[i][j] && \
				ft_isspace(game->map->map_data[i][j]))
			j++;
		while (game->map->map_data[i][j])
		{
			if (!validate_map_element(game->map->map_data[i][j], &p_count))
				clean_error(game, "Invalid character in map");
			j++;
		}
		i++;
	}
	if (p_count == 0)
		return (0);
	else if (p_count > 1)
		clean_error(game, "Multiple players found in map");
	return (1);
}
