/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:48:30 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/28 14:15:59 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open the map file.");
	return fd;
}

int	is_empty_line(char *line)
{
	// Returns true if the line is empty or contains only spaces
	while (*line)
	{
		if (!ft_isspace(*line))  // Check if the line has non-space characters
			return (0);
		line++;
	}
	return (1);
}

char	*trim_whitespace(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == ' '))
	{
		str[len - 1] = '\0';  // Replace newline or space with null terminator
		len--;
	}
	return (str);
}

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





/*
void	calculate_map_dimensions(t_map *map)
{
	int	i;
	int	current_width;

	i = 0;
	while (map->map_data[i])
	{
		current_width = ft_strlen(map->map_data[i]);
		if (current_width > map->width)
			map->width = current_width;  // Update width to the longest line
		map->height++;  // Increment the map height for each row
		i++;
	}
}

void	pad_map_rows(t_map *map)
{
	int		i;
	char	*padding;
	int		row_length;
	int		padding_size;

	i = 0;
	while (i < map->height)
	{
		row_length = ft_strlen(map->map_data[i]);
		if (row_length < map->width)
		{
			// Calculate the padding needed for the current row
			padding_size = map->width - row_length;
			padding = ft_calloc(padding_size + 1, sizeof(char));
			if (!padding)
				ft_error("Failed to allocate memory for padding");
			ft_memset(padding, ' ', padding_size);

			// Append the padding to the current row
			map->map_data[i] = ft_strjoin_free(map->map_data[i], padding);  // Assume it frees the first argument
		}
		i++;
	}
} */
