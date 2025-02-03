/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:29 by keramos-          #+#    #+#             */
/*   Updated: 2025/02/03 20:00:16 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "struct.h"

# ifndef MMAP_DEBUG_MSG
#  define MMAP_DEBUG_MSG 0
# endif

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
# define TXT_EXTS ".xpm"
# define W_WIDTH 1920   // Set default width
# define W_HEIGHT 960  // Set default height
# define MAX_LINES 1024 // Adjust based on expected map size
# define MOVE_SPEED 0.006
# define ROT_SPEED 0.01
# define INTRO "textures/intro.xpm"
#define DOOR_TEXTURE "texture/door.xpm"

/* Mini map */
# define CELL_SIZE 128
# define MINI_CELL_SIZE 16
# define MINI_PLAYER_SIZE 16

/*  Colors mini map */
#define COLOR_WALL 0x696969
#define COLOR_FLOOR 0xFFFFFF
#define COLOR_PLAYER 0x0000FF
#define COLOR_SPACE 0x000000


/* ************************************************************************** */
/*                                   SRC                                      */
/* ************************************************************************** */

void	art(const char *map_name);
void	control_opction(const char *map_name);

/*                                 Validate                                   */

void	check_argc(int argc, char **argv);
int		check_extension(char *filename);
void	check_map_file(char *filename);
int		parse_texture(char *line, t_txt *txt);
int		extract_rgb(char *line);
char	*get_texture_path(char *line, int j);
int		validate_map_initial(t_map *map);
int		validate_player_count(int player_count);
int		process_cell(t_map *map, int row, int col, int *player_count);
int		is_map_enclosed(t_map *map);
int		validate_map(t_game *game);
int		check_adjacents_not_void(t_map *map, int row, int col);
int		is_valid_char(char c);
char	get_map_char(t_map *map, int row, int col);
int		extension(char *filename);
int		check_file(char *filename);

/*                                  Init                                      */

void	initialize_game(t_game *game);
void	init_mlx(t_game *game);
void	init_imgs(t_game *game);
void	init_txt(t_txt *txt);
void	init_map(t_game *game);
void	init_player(t_player *player);
void	init_ray(t_ray *ray);
void	init_keys(t_keys *keys);
void	load_txt(t_game *game);
void	init_txt_path(t_game *game, t_imgs *img, char *path);

/*                                 Parsing                                    */

void	parse_file(t_game *game, char *filename);
char	*parse_texture_and_colors(int fd, t_txt *txt);
void	load_map(int fd, t_map *map, char *first_line);
void	calculate_map_dimensions(t_map *map);
void	init_player_NO_SO(t_player *player);
void	init_player_EA_WE(t_player *player);
void	initialize_player(t_game *game);


/*                                  Event                                     */

int		key_handler(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	ft_events(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	handle_movement(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

/*                                  Utils                                     */

void	clean_imgs(t_imgs *imgs);
int		close_handler(t_game *game);
void	ft_error(char *str);
int		open_file(char *filename);
char	*read_and_trim_line(int fd);
char	*trim_whitespace(char *str);
int		is_empty_line(char *line);
void	free_map(t_map *map);
void	free_split(char **split);

/*                                 Render                                     */

void	cast_ray(t_game *game, int x);
void	calculate_step(t_game *game);
void	perform_dda(t_game *game);
void	calculate_wall(t_game *game);
int		start_game(t_game *game);
void	draw_line(t_game *game, int x);
int		raycast(t_game *game);
void	draw_pixel(t_imgs *img, int x, int y, int color);
void	coordinate_texture(t_game *game);
void	correct_texture(t_game *game);
void	render_frame(t_game *game);

void	render_mini_player(t_game *game);
void	render_mini_direction(t_game *game);
void	render_mini_map(t_game *game);
void	render_mini(t_game *game);
void	draw_cell(int x, int y, int color, t_game *game);
void	toggle_door(t_game *game);

/* extra for the moment  */
void	free_textures_imgs(t_txt *txt, void *mlx);
void	free_mlx(t_game *game);

#endif
