/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_integration.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:00:36 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:17:37 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "test_validator.h"

/**
 * Validates a .cub file using the validator library
 *
 * @param filepath Path to the .cub file
 * @return 0 if valid, 1 if invalid
 */
int	validate_map_file(const char *filepath)
{
	t_val_cubfile	cubfile;

	if (!val_validate_cubfile(filepath, &cubfile))
	{
		ft_printf("Error\n%s\n", cubfile.error_msg);
		return (1);
	}
	ft_printf("Map validation passed!\n");
	return (0);
}