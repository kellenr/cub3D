/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:36:06 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 20:40:11 by keramos-         ###   ########.fr       */
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
