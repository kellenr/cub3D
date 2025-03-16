/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:49:00 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:26:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Checks if a character is a valid map character
 */
static bool	val_is_map_char(char c)
{
	// Accept all valid map characters including spaces
	if (c == ' ' || c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == 'D'
		|| c == '\t' || c == '\r')
		return (true);
	return (false);
}

/**
 * Checks if a character is a valid non-space map element
 */
static bool	val_is_valid_element(char c)
{
	// These are the core gameplay elements
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == 'D')
		return (true);
	return (false);
}

/**
 * Checks if a line is part of the map
 */
bool	val_is_map_line(char *line)
{
	int	i;
	int	found_valid;

	i = 0;
	found_valid = 0;
	
	if (!line)
		return (false);
		
	while (line[i])
	{
		
		if (!val_is_map_char(line[i]))
			return (false);
		
		
		if (val_is_valid_element(line[i]))
			found_valid = 1;
		i++;
	}
	return (found_valid);
}

/**
 * Processes a single line of the map
 */
bool	val_process_map_line(char *line, int row, t_val_cubfile *cubfile)
{
	int	col;
	int	len;

	col = 0;
	if (!line)
		return (false);
		
	while (line[col] && col < MAX_MAP_WIDTH)
	{
		if (line[col] == '\t')
			cubfile->map.grid[row][col] = ' '; // Convert tabs to spaces
		else if (line[col] == '\r')
			; // Skip carriage returns
		else
			cubfile->map.grid[row][col] = line[col];
		col++;
	}
	cubfile->map.grid[row][col] = '\0';
	len = col;
	if (len > cubfile->map.width)
		cubfile->map.width = len;
	return (true);
}

/**
 * Safely checks if there are more map lines after an empty line
 */
bool	val_check_more_map_lines(int fd, t_val_cubfile *cubfile)
{
	char	*peek_line;
	bool	more_map_lines;
	char	*peek_trimmed;
	long	original_pos;

	original_pos = lseek(fd, 0, SEEK_CUR);
	more_map_lines = false;
	peek_line = val_read_line(fd);
	
	while (peek_line != NULL)
	{
		peek_trimmed = val_trim_whitespace(peek_line);
		if (peek_trimmed[0] != '\0' && val_is_map_line(peek_trimmed))
		{
			more_map_lines = true;
			free(peek_line);
			break;
		}
		free(peek_line);
		peek_line = val_read_line(fd);
	}
	
	lseek(fd, original_pos, SEEK_SET);
	
	if (more_map_lines)
	{
		val_set_error(cubfile, "Empty line within map");
		return (true);
	}
	return (false);
}

/**
 * Handles an empty line during map parsing
 */
bool	val_handle_empty_line(int fd, t_val_cubfile *cubfile, bool *map_ended)
{
	if (val_check_more_map_lines(fd, cubfile))
		return (false);
	*map_ended = true;
	return (true);
}