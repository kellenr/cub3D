/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:42:29 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/22 19:33:50 by kellen           ###   ########.fr       */
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

# ifndef BONUS
#  define BONUS 0
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
# define W_WIDTH 1920
# define W_HEIGHT 960
# define MAX_LINES 1024
# define MOVE_SPEED 0.02
# define ROT_SPEED 0.010
# define INTRO1 "texture/intro1.xpm"
# define DOOR1 "texture/wall2.xpm"

// /* Mini map */
# define MINIMAP_SIZE 128
# define MINI_CELL_SIZE 7
# define VIEWPORT_WIDTH 15
# define VIEWPORT_HEIGHT 15
# define MINIMAP_OFFSET 20
# define PLAYER_DOT_SIZE 10

/* Scoop minimap constants */
# define SCOOP_SIZE 13
# define MINI_SCOOP_CELL_SIZE 12
# define SCOOP_MARGIN 20

/*  Colors mini map */
# define COLOR_WALL 0x696969
# define COLOR_FLOOR 0xFFFFFF
# define COLOR_PLAYER 0x0000FF
# define COLOR_SPACE 0xAAAAAA

/* ************************************************************************** */
/*                                   SRC                                      */
/* ************************************************************************** */

void	art(const char *map_name);
void	control_opction(const char *map_name);

/*                                 Validate                                   */

void	check_argc(int argc, char **argv);
int		check_extension(char *filename);
void	check_map_file(char *filename);
int		extract_rgb(t_game *game);
void	validate_single_rgb(char *tk, char **tokens, t_game *game);
void	validate_rgb_tokens(char **tokens, t_game *game);
void	validate_color_ids(t_game *game);
int		parse_texture(t_game *game);
int		parse_texture2(t_game *game);
int		parse_colors(t_game *game);
void	validate_map(t_game *game);
int		valid_player(t_game *game);
int		valid_layout(t_game *game);
int		is_valid_element(char c);
int		validate_map_element(char c, int *p_count);
int		is_adjacent_to_space(t_game *game, int y, int x);
int		check_row_enclosed(t_game *game, int i);
int		check_boundaries(t_game *game);
int		check_spaces_adjacent(t_game *game);

/*                                  Init                                      */

void	initialize_game(t_game *game);
void	init_map(t_game *game);
void	init_ray(t_ray *ray);
void	init_keys(t_keys *keys);
void	init_player(t_player *player);
void	init_mlx(t_game *game);
void	init_imgs(t_game *game);
void	init_txt_path(t_game *game, t_imgs *img, char *path);
void	init_txt(t_txt *txt);
int		load_textures(t_game *game);
void	load_extra(t_game *game);

/*                                 Parsing                                    */

void	parse_file(t_game *game, char *filename);
int		parse_content(t_game *game);
char	*get_texture_path(t_game *game, int j);
void	id_missing(t_game *game);
int		validate_texture_path(t_game *game, char *path);
int		is_valid_char(char c);
int		is_valid_char(char c);
int		is_valid_line(t_game *game);
int		parse_map(t_game *game);
int		is_map(t_game *game);
int		valid_map_save(t_game *game);
void	init_player_no_so(t_player *player);
void	init_player_ea_we(t_player *player);
void	initialize_player(t_game *game);

/*                                  Event                                     */

void	handle_game_keys(int keycode, t_game *game);
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
void	free_split(char **split);
void	free_textures_imgs(t_txt *txt, void *mlx);
void	free_mlx(t_game *game);
void	free_textures(t_txt *txt);
void	free_game(t_game *game);
void	free_map(t_map *map);
void	ft_error(char *str);
void	clean_error(t_game *game, char *msg);
int		open_file(char *filename);
int		is_empty_line(char *line);
int		check_element(t_game *game);
void	save_map(t_game *game, int i);
void	line_jump(t_game *game);

/*                                 Render                                     */

void	calculate_ray(t_game *game, t_ray *ray, int x);
void	calculate_step_and_side_dist(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calculate_wall_distance(t_game *game, t_ray *ray);
void	determine_texture(t_game *game, t_ray *ray);
void	cast_rays(t_game *game);

void	put_pixel(t_game *game, int x, int y, int color);
void	draw_ceiling(t_game *game, int x, int y_end);
void	draw_floor(t_game *game, int x, int y_start);
void	draw_wall_textured(t_game *game, int x);
void	draw_vertical_line(t_game *game, int x);
void	render_frame(t_game *game);

void	draw_map_square(t_game *game, int x, int y, int color);
void	draw_player_on_minimap(t_game *game);
void	draw_minimap(t_game *game);
void	draw_player(t_game *game, int x, int y);
void	draw_direction_line2(t_game *game, int pos[2], \
			int end[2], int delta[2]);
void	draw_direction_line(t_game *game, int start_x, int start_y);
int		calc_line_error(int delta[2]);
void	line_step_y(int pos[2], int step[2], int delta[2], int *err);
void	line_step_x(int pos[2], int step[2], int delta[2], int *err);
void	init_line_vars(int pos[2], int end[2], int delta[2], int step[2]);
void	calc_dir_endpoint(t_game *game, int start_x, int start_y, int end[2]);

/*                                 Game Loop                                  */

void	display_intro(t_game *game);
int		start_game(t_game *game);
void	init_game_loop(t_game *game);

/* extra for the moment  */

void	display_intro(t_game *game);
void	start_intro(t_game *game);
void	toggle_door(t_game *game);

void	draw_mini_viewport(t_game *game);
void	draw_scoop_map_tiles(t_game *game);
void	draw_scoop_background(t_game *game);
void	draw_scoop_border(t_game *game);
void	draw_player_in_scoop(t_game *game);
void	draw_direction_in_scoop(t_game *game);
int		get_tile_color(char tile);
char	get_map_tile(t_game *game, int map_x, int map_y);
void	draw_map_square_scoop(t_game *game, int x, int y, int color);
void	calculate_scoop_position(int *pos_x, int *pos_y);

#endif
