/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_element_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:48:41 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:24:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Parses an element line (texture or color)
 */
bool	val_parse_element_line(char *line, t_val_cubfile *cubfile)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 || 
		ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		return (val_parse_texture(line, cubfile));
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		return (val_parse_color(line, cubfile));
	val_set_error(cubfile, "Invalid element identifier");
	return (false);
}

/**
 * Validates a texture path has .xpm extension and exists
 */
bool	val_validate_texture_path(char *path, t_val_cubfile *cubfile)
{
	int		fd;
	size_t	len;

	/* Skip file existence check if testing mode is enabled */
	if (g_val_texture_files_skip)
		return (true);

	if (!path || path[0] == '\0')
	{
		val_set_error(cubfile, "Texture path is empty");
		return (false);
	}
	len = ft_strlen(path);
	if (len < 5 || ft_strcmp(path + len - 4, ".xpm") != 0)
	{
		val_set_error(cubfile, "Texture must have .xpm extension");
		return (false);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		val_set_error(cubfile, "Cannot open texture file");
		return (false);
	}
	close(fd);
	return (true);
}

/**
 * Parses a texture element line
 */
bool	val_parse_texture(char *line, t_val_cubfile *cubfile)
{
	char	id[3];
	char	path[MAX_PATH_LEN];

	id[0] = line[0];
	id[1] = line[1];
	id[2] = '\0';
	line += 2;
	while (*line && ft_isspace(*line))
		line++;
	ft_strncpy(path, line, MAX_PATH_LEN - 1);
	path[MAX_PATH_LEN - 1] = '\0';
	if (!val_validate_texture_path(path, cubfile))
		return (false);
	return (val_find_matching_texture(id, path, cubfile));
}

/**
 * Finds the matching texture in the cubfile struct
 */
bool	val_find_matching_texture(char *id, char *path, t_val_cubfile *cubfile)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(id, cubfile->textures[i].id) == 0)
		{
			if (cubfile->textures[i].is_set)
			{
				val_set_error(cubfile, "Duplicate texture definition");
				return (false);
			}
			ft_strcpy(cubfile->textures[i].path, path);
			cubfile->textures[i].is_set = true;
			return (true);
		}
		i++;
	}
	return (false);
}