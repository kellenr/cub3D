/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:53:49 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/27 01:46:59 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*parse_texture_and_colors(int fd, t_txt *txt)
{
	char	*line;
	int		identifiers_found;
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
		if (parse_texture(trimmed, txt))
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
