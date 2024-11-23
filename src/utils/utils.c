/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:48:30 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/22 23:14:09 by keramos-         ###   ########.fr       */
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
	return fd;
}

/*
 * Function to check if a line is empty or contains only spaces
 * Returns 1 if the line is empty, 0 otherwise
 */
int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))  // Check if the line has non-space characters
			return (0);
		line++;
	}
	return (1);
}

/*
 * Function to trim leading and trailing whitespace from a string
 * Returns the trimmed string
 */
char	*trim_whitespace(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == ' ' || str[len - 1] == '\t'))
	{
		str[len - 1] = '\0';  // Replace newline or space with null terminator
		len--;
	}
	return (str);
}

/*
 * Function to read a line from a file descriptor and trim leading and
 * trailing whitespace
 * Returns the trimmed line or NULL if the line is empty
*/
char	*read_and_trim_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return NULL;
	line = trim_whitespace(line);
	if (is_empty_line(line))
	{
		free(line);
		return (read_and_trim_line(fd));  // Recursively skip empty lines
	}
	return (line);
}
