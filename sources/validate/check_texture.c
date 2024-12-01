/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:06 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/27 01:50:34 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


char	*get_texture_path(char *line, int j)
{
	int		len;
	char	*path;

	while (line[j] && ft_isspace(line[j]))
		j++;
	len = j;
	while (line[len] && !ft_isspace(line[len]) && line[len] != '\n')
		len++;
	path = ft_substr(line, j, len - j);
	if (!path)
		return (NULL);
	while (line[len] && ft_isspace(line[len]))
		len++;
	if (line[len] && line[len] != '\n')
	{
		free(path);
		return (NULL);
	}
	return (path);
}

/*
 * Function to parse the texture identifiers and colors from the file.
 * Expects a line with one of the following identifiers:
 * NO, SO, WE, EA, F, C
 * Parses the corresponding texture or color value and stores it in the
 * txt structure.
 * Returns 1 if the identifier is valid, 0 otherwise.
 * If the identifier is not recognized, the function does nothing.
 */
int	parse_texture(char *line, t_txt *txt)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		txt->north = get_texture_path(line, 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		txt->south = get_texture_path(line, 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		txt->west = get_texture_path(line, 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		txt->east = get_texture_path(line, 3);
	else if (line[0] == 'F')
		txt->floor_color = extract_rgb(line + 1);
	else if (line[0] == 'C')
		txt->ceiling_color = extract_rgb(line + 1);
	else
		return 0;
	// free(line);
	// if (!txt->north || !txt->south || !txt->west || !txt->east)
	// 	ft_error("Error: Invalid texture path.");
	return 1;
}

/*
 * Function to extract RGB values from a string.
 * Expects a string in the format "R,G,B" where R, G, and B are integers.
 * Returns the combined RGB value as an integer.
 */
int	extract_rgb(char *line)
{
	int	r;
	int	g;
	int	b;
	char	**rgb;

	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_split(rgb);
		ft_error("Error: Invalid RGB format. Expected 'R,G,B'.");
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_split(rgb);
		ft_error("Error: RGB values must be between 0 and 255.");
	}
	free_split(rgb);
	return ((r << 16) | (g << 8) | b);
}
