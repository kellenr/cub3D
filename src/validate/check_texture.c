/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:06 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/28 15:54:37 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		// Check if it's a map line (starts with '1' or '0' after trimming)
		if (trimmed[0] == '1')
		{
			free(trimmed);
			return (line);
		} // Return the line if it starts the map section

		// Parse texture/color identifiers
		result = parse_texture(line, txt);
		if (result == 1)
			identifiers_found++;
		else
			printf("Invalid line in file (unknown identifier): %s\n", line);

		free(line);  // Free the line only once
	}
	// Verify all required textures and colors are set
	// // if (!txt->north || !txt->south || !txt->west || !txt->east || txt->floor_color == -1 || txt->ceiling_color == -1)
	// // 	ft_error("Error: Missing required textures or colors.");
	// // Verify that all required textures/colors were found
	if (identifiers_found < 6)
		ft_error("Error: Missing one or more required texture/color identifiers.");
	return (NULL);
}
