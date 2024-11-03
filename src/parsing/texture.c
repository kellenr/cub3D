/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:53:49 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/28 13:41:37 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	parse_texture(char *line, t_txt *txt)
{
	if (strncmp(line, "NO ", 3) == 0)
		txt->north = strdup(line + 3);
	else if (strncmp(line, "SO ", 3) == 0)
		txt->south = strdup(line + 3);
	else if (strncmp(line, "WE ", 3) == 0)
		txt->west = strdup(line + 3);
	else if (strncmp(line, "EA ", 3) == 0)
		txt->east = strdup(line + 3);
	else if (line[0] == 'F')
	{
		txt->floor_color = extract_rgb(line + 1);
		printf("Parsed Floor color: %d\n", txt->floor_color);
	}
	else if (line[0] == 'C')
	{
		txt->ceiling_color = extract_rgb(line + 1);
		printf("Parsed Ceiling color: %d\n", txt->ceiling_color);
	}
	else
	{
		printf("Invalid line in file (unknown identifier): %s\n", line);
		return 0;
	}
	return 1;
}

int	extract_rgb(char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	r = ft_atoi(line + i);
	while (line[i] && line[i] != ',')
		i++;
	if (line[i++] != ',')
		ft_error("Invalid RGB format");
	g = ft_atoi(line + i);
	while (line[i] && line[i] != ',')
		i++;
	if (line[i++] != ',')
		ft_error("Invalid RGB format");
	b = ft_atoi(line + i);
	printf("Extracted RGB values: r=%d, g=%d, b=%d\n", r, g, b);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("RGB values must be between 0 and 255");
	return (r << 16) | (g << 8) | b;  // Combine R, G, B into a single integer
}


// void parse_color(char *line, t_txt *textures)
// {
//     int r, g, b;

//     if (line[0] == 'F')
//     {
//         if (sscanf(line + 1, " %d,%d,%d", &r, &g, &b) != 3)
//             ft_error("Invalid floor color.");
//         textures->floor_color = (r << 16) | (g << 8) | b;  // Convert to hex color
//     }
//     else if (line[0] == 'C')
//     {
//         if (sscanf(line + 1, " %d,%d,%d", &r, &g, &b) != 3)
//             ft_error("Invalid ceiling color.");
//         textures->ceiling_color = (r << 16) | (g << 8) | b;  // Convert to hex color
//     }
//     else
//         ft_error("Invalid color line.");
// }


// void parse_map_line(char *line, t_map *map, int row)
// {
//     int i = 0;

//     while (line[i])
//     {
//         if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S' &&
//             line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
//             ft_error("Invalid character in map.");

//         map->map_data[row][i] = line[i];  // Store the map grid character
//         i++;
//     }
// }

