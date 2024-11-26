/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:53:49 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/25 01:56:28 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to parse the texture identifiers and colors from the file.
 * Expects a line with one of the following identifiers:
 * NO, SO, WE, EA, F, C
 * Parses the corresponding texture or color value and stores it in the
 * txt structure.
 * Returns 1 if the identifier is valid, 0 otherwise.
 * If the identifier is not recognized, the function does nothing.
 */
int	parse_texture(char *line, t_txt *txt)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		txt->north = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		txt->south = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		txt->west = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		txt->east = ft_strdup(line + 3);
	else if (line[0] == 'F')
		txt->floor_color = extract_rgb(line + 1);
	else if (line[0] == 'C')
		txt->ceiling_color = extract_rgb(line + 1);
	else
		return 0;
	return 1;
}

/*
 * Function to extract RGB values from a string.
 * Expects a string in the format "R,G,B" where R, G, and B are integers.
 * Returns the combined RGB value as an integer.
 */
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
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("RGB values must be between 0 and 255");
	return (r << 16) | (g << 8) | b;  // Combine R, G, B into a single integer
}

int	*ft_xpm(t_game *game, char *path)
{
	int		x;
	int		y;
	int		*i;
	t_imgs	img;

	init_txt_path(game, &img, path);
	i = malloc(sizeof(int) * game->txt->size_h * game->txt->size_w);
	if (!i)
		ft_error("Failed to allocate memory for txt_data");
	y = 0;
	while (y < game->txt->size_h)
	{
		x = 0;
		while (x < game->txt->size_w)
		{
			i[game->txt->size_w * y + x] = img.pix[y * game->txt->size_w + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img.img);
	return (i);
}
// unsigned char *pixel = (unsigned char *)(img.pix + y * img.ln_len + x * (img.bitp / 8));
			// Assuming pixel data is in 0xAARRGGBB format
			// Adjust based on your MLX setup
			// i[game->txt->size_w * y + x] = (pixel[2] << 16) | (pixel[1] << 8) | (pixel[0]);
