/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_drap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:48:09 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 08:59:58 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draw direction line - part 2: drawing loop
void	draw_direction_line2(t_game *game, int pos[2], int end[2], int delta[2])
{
	int	err;
	int	i;

	err = calc_line_error(delta);
	i = 0;
	while (i < MINI_CELL_SIZE)
	{
		put_pixel(game, pos[0], pos[1], 0xFF0000);
		if (pos[0] == end[0] && pos[1] == end[1])
			break ;
		line_step_x(pos, game->step, delta, &err);
		line_step_y(pos, game->step, delta, &err);
		i++;
	}
}

// Line step calculation for x axis
void	line_step_x(int pos[2], int step[2], int delta[2], int *err)
{
	int	e2;

	e2 = *err;
	if (e2 > -delta[0])
	{
		*err = *err - delta[1];
		pos[0] = pos[0] + step[0];
	}
}

// Line step calculation for y axis
void	line_step_y(int pos[2], int step[2], int delta[2], int *err)
{
	int	e2;

	e2 = *err;
	if (e2 < delta[1])
	{
		*err = *err + delta[0];
		pos[1] = pos[1] + step[1];
	}
}

// Calculate initial error value for line drawing
int	calc_line_error(int delta[2])
{
	if (delta[0] > delta[1])
		return (delta[0] / 2);
	else
		return (-delta[1] / 2);
}

// Initialize line drawing variables
void	init_line_vars(int pos[2], int end[2], int delta[2], int step[2])
{
	delta[0] = abs(end[0] - pos[0]);
	delta[1] = abs(end[1] - pos[1]);
	if (pos[0] < end[0])
		step[0] = 1;
	else
		step[0] = -1;
	if (pos[1] < end[1])
		step[1] = 1;
	else
		step[1] = -1;
}
