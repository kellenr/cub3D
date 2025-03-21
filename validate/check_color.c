/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:13:27 by kellen            #+#    #+#             */
/*   Updated: 2025/03/21 04:25:19 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Function to extract RGB values from a string.
 * Expects a string in the format "R,G,B" where R, G, and B are integers.
 * Returns the combined RGB value as an integer.
 */
int	extract_rgb(t_game *game)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	rgb = ft_split(game->n_line + 1, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_split(rgb);
		clean_error(game, "Invalid RGB format. Expected 'R,G,B'.");
	}
	validate_rgb_tokens(rgb, game);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_split(rgb);
		clean_error(game, "RGB values must be between 0 and 255.");
	}
	free_split(rgb);
	return ((r << 16) | (g << 8) | b);
}

/*
 * This function validates that each of the three tokens contains only digits
 * after skipping any leading whitespace. If a token is empty or contains a
 * non-digit,it frees the token array and calls clean_error().
*/
void	validate_single_rgb(char *tk, char **tokens, t_game *game)
{
	int	j;
	int	len;

	while (*tk && ft_isspace(*tk))
		tk++;
	len = ft_strlen(tk);
	while (len > 0 && ft_isspace(tk[len - 1]))
		len--;
	if (len == 0)
	{
		free_split(tokens);
		clean_error(game, "Missing a numeric value in RGB.");
	}
	j = 0;
	while (j < len)
	{
		if (!ft_isdigit(tk[j]))
		{
			free_split(tokens);
			clean_error(game, "RGB values must be numeric.");
		}
		j++;
	}
}

void	validate_rgb_tokens(char **tokens, t_game *game)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		validate_single_rgb(tokens[i], tokens, game);
		i++;
	}
}

void	validate_color_ids(t_game *game)
{
	if (game->txt.floor_color == -1)
	{
		clean_error(game, "Missing floor color identifier.");
	}
	if (game->txt.ceiling_color == -1)
	{
		clean_error(game, "Missing ceiling color identifier.");
	}
}
