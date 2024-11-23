/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:06 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/22 23:26:37 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to check the texture identifiers in the file.
 * Reads the file line by line and checks for the texture identifiers.
 * If all identifiers are found, returns the line that starts the map section.
 * If the map section starts before all identifiers are found, returns NULL.
 * If an unknown identifier is found, prints an error message and returns NULL.
 *
 * fd: File descriptor of the map file.
 * txt: Pointer to the texture structure.
 *
 * returns: The line that starts the map section or NULL.
 */
char	*check_texture(int fd, t_txt *txt)
{
	char	*line;
	int		identifiers_found;
	int		result;
	char	*trimmed;

	identifiers_found = 0;
	while ((line = read_and_trim_line(fd)))
	{
		trimmed = ft_strtrim(line, " \t");
		if (trimmed[0] == '1' || trimmed[0] == '0')
		{
			free(trimmed);
			if (identifiers_found < 6)
				ft_error("Missing one or more required texture identifiers.");
			return (line);
		}
		result = parse_texture(line, txt);
		if (result == 1)
			identifiers_found++;
		else
			ft_printf("Invalid line in file (unknown identifier): %s\n", line);
		free(line);
		free(trimmed);
	}
	if (identifiers_found < 6)
		ft_error("Missing one or more required texture/color identifiers.");
	return (NULL);
}
