/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:02:24 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/24 23:14:01 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_textures(t_txt *txt)
{
	printf("North texture: %s\n", txt->north ? txt->north : "Not set");
	printf("South texture: %s\n", txt->south ? txt->south : "Not set");
	printf("West texture: %s\n", txt->west ? txt->west : "Not set");
	printf("East texture: %s\n", txt->east ? txt->east : "Not set");

	// Print floor and ceiling colors in RGB format if they are set
	if (txt->floor_color >= 0)
		printf("Floor color: #%06X\n", txt->floor_color);
	else
		printf("Floor color: Not set\n");

	if (txt->ceiling_color >= 0)
		printf("Ceiling color: #%06X\n", txt->ceiling_color);
	else
		printf("Ceiling color: Not set\n");
}


