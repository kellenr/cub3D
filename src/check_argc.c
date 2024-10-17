/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:36:06 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/17 15:59:24 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_argc(int argc, char **argv)
{
	if (argc < 2)
		ft_error("We need a map, so you can start the game.");
	if (argc > 2)
		ft_error("Too many arguments, You just need one map file.");
	if (!check_extension(argv[1]))
		ft_error("The map file must have a .cub extension.");
	check_map_file(argv[1]);
}

int	check_extension(char *filename)
{
	int	len;
	int	ext_len;

	len = ft_strlen(filename);
	ext_len = ft_strlen(VALID_EXTS);
	if (len > ext_len && ft_strcmp(filename + len - ext_len, VALID_EXTS) == 0)
		return (1);
	return (0);
}

void	check_map_file(char *filename)
{
	int		fd;
	char	buffer[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("The map file does not exist or cannot be opened.");
	if (read(fd, buffer, 1) <= 0)
		ft_error("The map file is empty.");
	close(fd);
}

int	is_map_enclosed(t_map *map)
{
	int i;

	// Check top and bottom rows
	i = 0;
	while (i < map->width)
	{
		if (map->map_data[0][i] != '1')
		{
			ft_printf("Top border not closed at column %d (value: %c)\n", i, map->map_data[0][i]);
			return (0);
		}
		if (map->map_data[map->height - 1][i] != '1')
		{
			ft_printf("Bottom border not closed at column %d (value: %c)\n", i, map->map_data[map->height - 1][i]);
			return (0);
		}
		i++;
	}
	// Check left and right columns
	i = 0;
	while (i < map->height)
	{
		if (map->map_data[i][0] != '1')
		{
			ft_printf("Left border not closed at row %d (value: %c)\n", i, map->map_data[i][0]);
			return (0);
		}
		if (map->map_data[i][map->width - 1] != '1')
		{
			ft_printf("Right border not closed at row %d (value: %c)\n", i, map->map_data[i][map->width - 1]);
			return (0);
		}
		i++;
	}

	return (1);
}
