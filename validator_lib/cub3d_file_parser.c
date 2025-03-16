/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_file_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:48:54 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:25:20 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Validates that the file has a .cub extension
 */
bool	val_validate_file_extension(const char *filepath, t_val_cubfile *cubfile)
{
	size_t	len;
	size_t	ext_len;

	if (!filepath)
	{
		val_set_error(cubfile, "Filepath is NULL");
		return (false);
	}
	len = ft_strlen(filepath);
	ext_len = 4;
	if (len < 5 || ft_strcmp((char *)filepath + len - ext_len, ".cub") != 0)
	{
		val_set_error(cubfile, "File must have .cub extension");
		return (false);
	}
	return (true);
}

/**
 * Trims leading and trailing whitespace from a string
 */
char	*val_trim_whitespace(char *str)
{
	char	*end;

	if (!str)
		return (str);
		
	while (ft_isspace(*str))
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	*(end + 1) = 0;

	return (str);
}

/**
 * Checks if all required elements (textures and colors) are set
 */
bool	val_check_all_elements_set(t_val_cubfile *cubfile)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!cubfile->textures[i].is_set)
		{
			val_set_error(cubfile, "Missing texture definition");
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (!cubfile->colors[i].is_set)
		{
			val_set_error(cubfile, "Missing color definition");
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * Processes a line during file parsing
 */
bool	val_process_line(int fd, char *line, t_val_cubfile *cubfile,
		bool *found_map)
{
	char	*trimmed_line;
	bool	result;

	if (!line)
		return (false);
		
	trimmed_line = val_trim_whitespace(line);
	if (trimmed_line[0] == '\0')
		return (true);
		
	if (val_is_map_line(trimmed_line))
	{
		*found_map = true;
		result = val_parse_map(fd, trimmed_line, cubfile);
		return (result);
	}
	
	return (val_parse_element_line(trimmed_line, cubfile));
}

/**
 * Reads and parses the content of a .cub file
 */
bool	val_parse_file_content(int fd, t_val_cubfile *cubfile)
{
	char	*line;
	bool	found_map;
	bool	result;

	found_map = false;
	
	while (1) 
	{
		line = val_read_line(fd);
		if (!line)
			break;
			
		result = val_process_line(fd, line, cubfile, &found_map);
		free(line); // Free line after processing
		
		if (!result)
			return (false);
		if (found_map)
			break;
	}
	
	if (!val_check_all_elements_set(cubfile))
		return (false);
	if (!found_map)
	{
		val_set_error(cubfile, "No map found in file");
		return (false);
	}
	return (val_validate_map(cubfile));
}