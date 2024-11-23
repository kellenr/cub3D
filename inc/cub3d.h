/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:29 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/23 02:13:37 by keramos-         ###   ########.fr       */
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
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# define INTRO "textures/intro.xpm"

/* Mini map */
# define MINIMAP_SCALE 5
# define MINIMAP_SIZE 200
# define MINIMAP_MARGIN 20

/*  Colors mini map */
#define COLOR_WALL 0x000000FF      // Blue walls
#define COLOR_FLOOR 0x00FF00FF     // Green floor
#define COLOR_PLAYER 0xFFFF00FF    // Yellow player
#define COLOR_SPACE 0xFF0000FF // Red direction line


/* ************************************************************************** */
/*                                   SRC                                      */
/* ************************************************************************** */

void	art(const char *map_name);
void	control_opction(const char *map_name);

/*                                 Validate                                   */

void	check_argc(int argc, char **argv);
int		check_extension(char *filename);
void	check_map_file(char *filename);
char	*check_texture(int fd, t_txt *txt);
int		is_map_enclosed(t_map *map);
char	get_map_char(t_map *map, int row, int col);
int		is_valid_char(char c);
int		check_adjacents_not_void(t_map *map, int row, int col);
int		validate_map(t_game *game);
int		validate_map_initial(t_map *map);
int		process_cell(t_map *map, int row, int col, int *player_count);
int		validate_player_count(int player_count);

/*                                  Init                                      */

void	initialize_game(t_game *game);
void	init_mlx(t_game *game);
t_imgs	*init_imgs(t_game *game);
t_txt	*init_txt(t_game *game);
t_map	*init_map(t_game *game);
t_player	*init_player(void);

/*                                 Parsing                                    */

void	parse_file(t_game *game, char *filename);
int		parse_texture(char *line, t_txt *txt);
int		extract_rgb(char *line);
void	load_map(int fd, t_map *map, char *first_line);
void	calculate_map_dimensions(t_map *map);
void	initialize_player(t_game *game);


/*                                  Event                                     */

int		key_handler(int keycode, t_game *game);
void	display_intro(t_game *game);
void	start_intro(t_game *game);
void	ft_events(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	handle_movement(t_game *game);

/*                                  Utils                                     */

void	clean_init(t_game *game);
void	ft_error(char *str);
int		close_handler(t_game *game);
int		open_file(char *filename);
int		is_empty_line(char *line);
char	*trim_whitespace(char *str);
char	*read_and_trim_line(int fd);
void	free_texture(t_txt *txt);
void	free_player(t_player *player);
void	free_map(t_map *map);
void	free_game(t_game *game);
/*                                 Render                                     */

// void	render(t_game *game);
int		raycast(t_game *game);
void	init_ray(t_ray *ray, t_game *game, int x);
void	calculate_step_and_side_dist(t_ray *ray, t_game *game);
void	perform_dda(t_ray *ray, t_game *game);
void	calculate_wall_height(t_ray *ray, t_player *player);
void	draw_rectangle(t_imgs *img, int x, int y, int color, int size);
void	render_minimap(t_game *game);
void	my_mlx_pixel_put(t_imgs *img, int x, int y, int color);


/* extra for the moment  */
void	get_txt(t_game *game, t_ray *ray);
void	init_pix(t_game *game);
void	init_txt_path(t_game *game, t_imgs *img, char *path);
void	init_textures(t_game *game);
int	*ft_xpm(t_game *game, char *path);
void	draw_line(t_game *game, t_txt *txt, t_ray *ray, int x);
void	frame_img_pix(t_game *game, t_imgs *img, int x, int y);
void	render_frame(t_game *game);
void	rendercast(t_game *game);
int	render(t_game *game);

#endif
