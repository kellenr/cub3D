/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:49:23 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/13 22:04:17 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validator.h"

/**
 * Check if read operations are complete and handle cleanup
 */
static char	*val_check_read_result(char *line, int i, int bytes_read)
{
	line[i] = '\0';
	if (i == 0 && bytes_read <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * Fill buffer from file descriptor
 */
static int	val_fill_buffer(int fd, char *buf)
{
	return (read(fd, buf, 4096));
}

/**
 * Process character reading from buffer
 */
static char	*val_process_line(char *line, int fd)
{
	static char	buf[4096];
	static int	pos;
	static int	bytes;
	int			i;
	char		c;

	i = 0;
	while (1)
	{
		if (pos >= bytes)
		{
			pos = 0;
			bytes = val_fill_buffer(fd, buf);
			if (bytes <= 0)
				break ;
		}
		c = buf[pos++];
		if (c == '\n')
			break ;
		line[i++] = c;
	}
	return (val_check_read_result(line, i, bytes));
}

/**
 * Reads a line from file descriptor
 */
char	*val_read_line(int fd)
{
	char	*line;

	if (fd < 0)
		return (NULL);
	line = malloc(1024);
	if (line == NULL)
		return (NULL);
	return (val_process_line(line, fd));
}

/**
 * Checks if a position contains a wall
 */
bool	val_is_position_wall(int x, int y, t_val_cubfile *cubfile)
{
	if (!val_is_position_valid(x, y, cubfile))
		return (false);
	return (cubfile->map.grid[y][x] == '1');
}