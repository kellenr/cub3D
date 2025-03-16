/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_color_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:48:23 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:22:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Checks if RGB values are valid (0-255)
 */
bool	val_check_rgb_values(int r, int g, int b, t_val_cubfile *cubfile)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		val_set_error(cubfile, "Invalid color values (must be 0-255)");
		return (false);
	}
	return (true);
}

/**
 * Counts the number of commas in a string
 */
int	val_count_commas(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}

/**
 * Checks if color ID is valid and not duplicated
 * Returns color index (0 or 1) or -1 if invalid
 */
int	val_check_color_id(char id, t_val_cubfile *cubfile)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (id == cubfile->colors[i].id[0])
		{
			if (cubfile->colors[i].is_set)
			{
				val_set_error(cubfile, "Duplicate color definition");
				return (-1);
			}
			return (i);
		}
		i++;
	}
	/* Invalid color identifier */
	return (-1);
}

/**
 * Checks if a color string has the correct format
 */
bool	val_check_color_format(char *color_str, t_val_cubfile *cubfile)
{
	int	commas;

	if (!color_str || color_str[0] == '\0')
	{
		val_set_error(cubfile, "Color definition is empty");
		return (false);
	}
	commas = val_count_commas(color_str);
	if (commas != 2)
	{
		val_set_error(cubfile, "Invalid color format (must have exactly 2 commas)");
		return (false);
	}
	return (val_check_color_values(color_str, cubfile));
}

/**
 * Checks that the color string has exactly 3 values
 */
bool	val_check_color_values(char *color_str, t_val_cubfile *cubfile)
{
	int		values;
	char	*ptr;

	values = 0;
	ptr = color_str;
	while (*ptr)
	{
		if ((*ptr >= '0' && *ptr <= '9')
			&& (ptr == color_str || *(ptr - 1) == ',' || ft_isspace(*(ptr - 1))))
			values++;
		ptr++;
	}
	if (values != 3)
	{
		val_set_error(cubfile, "Invalid color format (must have exactly 3 values)");
		return (false);
	}
	return (true);
}

/* These functions have been moved to cub3d_color_validator_extra.c */