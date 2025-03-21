/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:48:30 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:22:14 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to open a file and return the file descriptor
 * Exits the program with an error message if the file cannot be opened
 */
int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open the map file.");
	return (fd);
}

/*
 * Function to check if a line is empty or contains only spaces
 * Returns 1 if the line is empty, 0 otherwise
 */
int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

int	check_element(t_game *game)
{
	if (ft_strncmp(game->n_line, "NO", 2) == 0 || \
		ft_strncmp(game->n_line, "SO", 2) == 0 || \
		ft_strncmp(game->n_line, "WE", 2) == 0 || \
		ft_strncmp(game->n_line, "EA", 2) == 0 || \
		ft_strncmp(game->n_line, "F", 1) == 0 || \
		ft_strncmp(game->n_line, "C", 1) == 0)
		return (1);
	return (0);
}

void	line_jump(t_game *game)
{
	game->line = 0;
	game->n_line = get_next_line(game->fd);
	while (game->line < (game->s_map -1))
	{
		game->line++;
		free(game->n_line);
		game->n_line = get_next_line(game->fd);
	}
}
