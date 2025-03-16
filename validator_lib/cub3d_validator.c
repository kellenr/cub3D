/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:49:29 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:15:15 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/* Flag to skip texture file validation for testing */
bool	g_val_texture_files_skip = true;

/**
 * Initializes a t_val_cubfile struct with default values
 */
void	val_init_cubfile(t_val_cubfile *cubfile)
{
	cubfile->textures[0] = (t_val_texture){"NO", "", false};
	cubfile->textures[1] = (t_val_texture){"SO", "", false};
	cubfile->textures[2] = (t_val_texture){"WE", "", false};
	cubfile->textures[3] = (t_val_texture){"EA", "", false};
	cubfile->colors[0] = (t_val_color){"F", 0, 0, 0, false};
	cubfile->colors[1] = (t_val_color){"C", 0, 0, 0, false};
	cubfile->map.height = 0;
	cubfile->map.width = 0;
	cubfile->map.has_player = false;
	cubfile->map.player_dir = '\0';
	cubfile->map.player_x = -1;
	cubfile->map.player_y = -1;
	cubfile->error_msg[0] = '\0';
}

/**
 * Sets an error message in the cubfile struct with printf-style formatting
 */
void	val_set_error(t_val_cubfile *cubfile, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	vsnprintf(cubfile->error_msg, MAX_ERROR_LEN - 1, format, args);
	va_end(args);
	cubfile->error_msg[MAX_ERROR_LEN - 1] = '\0';
}

/**
 * Validates a .cub file
 */
bool	val_validate_cubfile(const char *filepath, t_val_cubfile *cubfile)
{
	int	fd;

	val_init_cubfile(cubfile);
	if (!val_validate_file_extension(filepath, cubfile))
		return (false);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		val_set_error(cubfile, "Failed to open file");
		return (false);
	}
	if (!val_parse_file_content(fd, cubfile))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}