/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_validator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:15:36 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:18:36 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_VALIDATOR_H
# define CUB3D_VALIDATOR_H

# include "cub3d.h"

/**
 * Validates a .cub file using the validator library
 *
 * @param filepath Path to the .cub file
 * @return 0 if valid, 1 if invalid
 */
int	validate_map_file(const char *filepath);

#endif