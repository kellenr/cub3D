/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parser2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:49:12 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:27:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/* Forward declarations for functions in cub3d_map_parser.c */
bool	val_is_map_line(char *line);
bool	val_process_map_line(char *line, int row, t_val_cubfile *cubfile);
bool	val_handle_empty_line(int fd, t_val_cubfile *cubfile, bool *map_ended);

/**
 * Handles a non-empty line during map parsing
 */
bool	val_handle_non_empty_line(char *trimmed, t_val_cubfile *cubfile,
		int *row, bool *map_ended)
{
	if (!trimmed)
		return (false);
		
	if (*map_ended)
	{
		if (val_is_map_line(trimmed))
		{
			val_set_error(cubfile, "Map continues after empty line");
			return (false);
		}
		return (true);
	}
	
	if (!val_is_map_line(trimmed))
	{
		val_set_error(cubfile, "Invalid character in map");
		return (false);
	}
	
	if (!val_process_map_line(trimmed, *row, cubfile))
		return (false);
		
	(*row)++;
	return (true);
}

/**
 * Processes a line during map parsing
 * THIS FUNCTION SHOULD NOT FREE THE LINE - it's already freed in file_parser
 */
bool	val_process_parsing(int fd, char *line, t_val_cubfile *cubfile,
		int *row, bool *map_ended)
{
	char	*trimmed;
	bool	result;

	if (!line)
		return (false);
		
	trimmed = val_trim_whitespace(line);
	if (trimmed[0] == '\0')
		result = val_handle_empty_line(fd, cubfile, map_ended);
	else
		result = val_handle_non_empty_line(trimmed, cubfile, row, map_ended);
	
	// DO NOT FREE LINE HERE - it's freed in the calling function
	
	return (result);
}

/**
 * Parses the map section of the file
 */
bool	val_parse_map(int fd, char *first_line, t_val_cubfile *cubfile)
{
	char	*line;
	int		row;
	bool	map_ended;

	if (!first_line)
		return (false);
		
	row = 0;
	map_ended = false;
	
	if (!val_process_map_line(first_line, row, cubfile))
		return (false);
	row++;
	
	while (row < MAX_MAP_HEIGHT)
	{
		line = val_read_line(fd);
		if (!line)
			break;
			
		if (!val_process_parsing(fd, line, cubfile, &row, &map_ended))
		{
			free(line); // Free line on error
			return (false);
		}
		
		free(line); // Free line after successful processing
	}
	
	cubfile->map.height = row;
	return (true);
}