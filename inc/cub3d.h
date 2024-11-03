/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:29 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/03 15:21:59 by keramos-         ###   ########.fr       */
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
# define INTRO "textures/intro.xpm"

/* ************************************************************************** */
/*                                   SRC                                      */
/* ************************************************************************** */


/*                                 Validate                                   */

void	check_argc(int argc, char **argv);
int		check_extension(char *filename);
void	check_map_file(char *filename);
char	*check_texture(int fd, t_txt *txt);
int		is_map_enclosed(t_map *map);
char	get_map_char(t_map *map, int row, int col);
int		is_valid_char(char c);
int		check_adjacents_not_void(t_map *map, int row, int col);
// int		validate_map_chars(t_map *map);
// int		is_map_valid_layout(t_map *map);
int		validate_map(t_game *game);

/*                                  Init                                      */

void	init_mlx(t_game *game);
void	init_game(t_game *game);
t_txt	*init_txt(t_game *game);
t_map	*init_map(t_game *game);
t_player	*init_player(void);

/*                                 Parsing                                    */

void	parse_file(t_game *game, char *filename);
int		parse_texture(char *line, t_txt *txt);
int		extract_rgb(char *line);
void	load_map(int fd, t_map *map, char *first_line);
void	store_map_line(t_map *map, char *line, int *row, int *capacity);
void	calculate_map_dimensions(t_map *map);

void	initialize_player(t_game *game);


/*                                  Event                                     */

int		key_handler(int keycode, t_game *game);
void	display_intro(t_game *game);
void	start_intro(t_game *game);
void	ft_events(t_game *game);

/*                                  Utils                                     */

void	clean_init(t_game *game);
void	ft_error(char *str);
int		close_handler(t_game *game);
int		open_file(char *filename);
int		is_empty_line(char *line);
char	*trim_whitespace(char *str);
char	*read_and_trim_line(int fd);

// void		free_game(t_game *game);
// void		free_map(t_map *map);

// char		*trim_newline(char *str);
// int			is_empty_line(char *line);
// char		*ft_strjoin_free(char *s1, char *s2);

// int			is_map_enclosed(t_map *map);
// int			validate_map_chars(t_map *map);
// int			is_map_valid_layout(t_map *map);
// int			validate_map(t_game *game);
// void		calculate_map_dimensions(t_map *map);
// void		pad_map_rows(t_map *map);
// int			open_map_file(const char *file_path);
// int			array_size(char **array);
// void		free_array(char **array);
// void		check_argc(int argc, char **argv);
// int			check_extension(char *filename);
// void		check_map_file(char *filename);
// void		parse_textures(t_txt *txt, int fd, t_map *map);
// // void		parse_textures(t_txt *txt, int fd);
// void		reset_structs(t_game *game);
// t_game		*init_game(const char *map_file);
// t_map		*init_map(t_game *game,int fd);
// t_player	*init_player(void);
// // char		**load_map(int fd);
// void		load_map(int fd, t_map *map, char *first_line);
// t_txt		*init_txtures(void);

// int			key_handler(int keysym, t_game *game);
// void		ft_events(t_game *game);
// int			close_handler(t_game *game);


#endif
