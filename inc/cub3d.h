/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:29 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/17 15:30:42 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "struct.h"

/* COLOR intro */
# define RT			"\033[0m"
# define R			"\033[1;31m"
# define P_G		"\033[1;38;2;186;255;201m"
# define P_B		"\033[1;38;2;186;225;255m"
# define P_L		"\033[1;38;2;255;186;255m"
# define P_M		"\033[1;38;5;183m"
# define P_P		"\033[1;38;2;255;209;220m"
# define P_R		"\033[1;38;2;255;179;186m"
# define R_P		"\033[38;2;255;179;186m"

# define VALID_EXTS ".cub"
# define W_WIDTH 1920   // Set default width
# define W_HEIGHT 960  // Set default height
# define MAX_LINES 1024 // Adjust based on expected map size

/* ************************************************************************** */
/*                                   SRC                                      */
/* ************************************************************************** */

void	ft_error(char *str);
void	check_argc(int argc, char **argv);
int		check_extension(char *filename);
void	check_map_file(char *filename);
void	free_game(t_game *game);
void	free_map(t_map *map);

void	init_window(t_game *game);
t_game	*init_game(const char *map_file);
t_mlx	*init_mlx(t_game *game);
t_imgs	*init_imgs(t_game *game);
t_map	*init_map(t_game *game, const char *map_file);
int		is_map_enclosed(t_map *map);
char	**load_map(const char *file_path);

int		key_handler(int keysym, t_game *game);
void	ft_events(t_game *game);
int		close_handler(t_game *game);

#endif
