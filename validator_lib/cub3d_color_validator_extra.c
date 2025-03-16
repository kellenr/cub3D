/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_color_validator_extra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:20:42 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:23:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Parses first part of color element line
 */
bool	val_parse_color_start(char *line, char *id, char **color_str)
{
	*id = line[0];
	line += 1;
	while (*line && ft_isspace(*line))
		line++;
	*color_str = line;
	return (true);
}

/**
 * Parses a color element line
 */
bool	val_parse_color(char *line, t_val_cubfile *cubfile)
{
	char	id;
	char	*color_str;
	int		color_index;

	val_parse_color_start(line, &id, &color_str);
	color_index = val_check_color_id(id, cubfile);
	if (color_index == -1)
		return (false);
	if (!val_check_color_format(color_str, cubfile))
		return (false);
	return (val_extract_rgb(color_index, color_str, cubfile));
}

/**
 * Extracts and validates RGB values
 */
bool	val_extract_rgb(int color_index, char *color_str, t_val_cubfile *cubfile)
{
	int		r;
	int		g;
	int		b;
	char	*token;

	r = ft_atoi(color_str);
	token = ft_strchr(color_str, ',');
	if (!token)
		return (false);
	g = ft_atoi(token + 1);
	token = ft_strchr(token + 1, ',');
	if (!token)
		return (false);
	b = ft_atoi(token + 1);
	if (!val_check_rgb_values(r, g, b, cubfile))
		return (false);
	cubfile->colors[color_index].r = r;
	cubfile->colors[color_index].g = g;
	cubfile->colors[color_index].b = b;
	cubfile->colors[color_index].is_set = true;
	return (true);
}