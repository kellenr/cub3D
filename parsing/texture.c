/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:53:49 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:12:54 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_content(t_game *game)
{
	game->n_line = get_next_line(game->fd);
	while (game->n_line)
	{
		game->line++;
		if (is_empty_line(game->n_line) && game->start != 1)
		{
			free(game->n_line);
			game->n_line = get_next_line(game->fd);
			continue ;
		}
		if (check_element(game))
			parse_texture(game);
		else if (!is_map(game))
		{
			if (!is_empty_line(game->n_line))
				clean_error(game, "Invalid element in file.");
		}
		free(game->n_line);
		game->n_line = get_next_line(game->fd);
	}
	if (!game->start || game->map->height == 0)
		clean_error(game, "No valid map found in file.");
	validate_color_ids(game);
	return (1);
}

char	*get_texture_path(t_game *game, int j)
{
	int		len;
	char	*path;

	while (game->n_line[j] && ft_isspace(game->n_line[j]))
		j++;
	len = j;
	while (game->n_line[len] && !ft_isspace(game->n_line[len]) && \
			game->n_line[len] != '\n')
		len++;
	path = ft_substr(game->n_line, j, len - j);
	while (game->n_line[len] && ft_isspace(game->n_line[len]))
		len++;
	if (game->n_line[len] && game->n_line[len] != '\n')
	{
		free(path);
		clean_error(game, "Unexpected characters after texture path.");
	}
	validate_texture_path(game, path);
	return (path);
}

void	id_missing(t_game *game)
{
	clean_error(game, "Missing one or more texture identifiers.");
}

int	validate_texture_path(t_game *game, char *path)
{
	int	len;
	int	fd;

	if (!path || *path == '\0')
	{
		free(path);
		clean_error(game, "Missing texture path.");
	}
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		free(path);
		clean_error(game, "Texture path must end with '.xpm'.");
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		clean_error(game, "Texture file does not exist or cannot be opened.");
	}
	close(fd);
	return (1);
}
