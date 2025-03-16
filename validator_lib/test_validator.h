/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:10:42 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/16 13:16:42 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_VALIDATOR_H
# define TEST_VALIDATOR_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <ctype.h>
# include <stdarg.h>
# include "../Libft/inclu/libft.h"

# define MAX_ERROR_LEN 256
# define MAX_PATH_LEN 256
# define MAX_MAP_HEIGHT 100
# define MAX_MAP_WIDTH 100

/* Global flags */
extern bool	g_val_texture_files_skip;

typedef struct s_val_texture
{
	char	*id;
	char	path[MAX_PATH_LEN];
	bool	is_set;
}	t_val_texture;

typedef struct s_val_color
{
	char	*id;
	int		r;
	int		g;
	int		b;
	bool	is_set;
}	t_val_color;

typedef struct s_val_map
{
	char	grid[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
	int		height;
	int		width;
	char	player_dir;
	int		player_x;
	int		player_y;
	bool	has_player;
}	t_val_map;

typedef struct s_val_cubfile
{
	t_val_texture	textures[4];
	t_val_color		colors[2];
	t_val_map		map;
	char		error_msg[MAX_ERROR_LEN];
}	t_val_cubfile;

/* Main validation functions - cub3d_validator.c */
bool	val_validate_cubfile(const char *filepath, t_val_cubfile *cubfile);
void	val_init_cubfile(t_val_cubfile *cubfile);
void	val_set_error(t_val_cubfile *cubfile, const char *format, ...);

/* File parsing functions - cub3d_file_parser.c */
bool	val_validate_file_extension(const char *filepath, t_val_cubfile *cubfile);
bool	val_parse_file_content(int fd, t_val_cubfile *cubfile);
bool	val_check_all_elements_set(t_val_cubfile *cubfile);
char	*val_trim_whitespace(char *str);

/* Element parsing functions - cub3d_element_parser.c */
bool	val_parse_element_line(char *line, t_val_cubfile *cubfile);
bool	val_parse_texture(char *line, t_val_cubfile *cubfile);
bool	val_find_matching_texture(char *id, char *path, t_val_cubfile *cubfile);
bool	val_parse_color(char *line, t_val_cubfile *cubfile);
bool	val_find_matching_color(char id, int r, int g, int b, t_val_cubfile *cubfile);

/* Map parsing functions - cub3d_map_parser.c */
bool	val_is_map_line(char *line);
bool	val_process_map_line(char *line, int row, t_val_cubfile *cubfile);
bool	val_check_more_map_lines(int fd, t_val_cubfile *cubfile);
bool	val_handle_empty_line(int fd, t_val_cubfile *cubfile, bool *map_ended);

/* Map parsing functions - cub3d_map_parser2.c */
bool	val_handle_non_empty_line(char *trimmed, t_val_cubfile *cubfile,
		int *row, bool *map_ended);
bool	val_process_parsing(int fd, char *line, t_val_cubfile *cubfile,
		int *row, bool *map_ended);
bool	val_parse_map(int fd, char *first_line, t_val_cubfile *cubfile);

/* Map validation functions - cub3d_map_validator.c */
bool	val_validate_map(t_val_cubfile *cubfile);
bool	val_check_player_position(t_val_cubfile *cubfile);
bool	val_check_map_closed(t_val_cubfile *cubfile);
bool	val_is_valid_map_char(char c);
bool	val_is_position_valid(int x, int y, t_val_cubfile *cubfile);
bool	val_check_position_enclosed(int x, int y, t_val_cubfile *cubfile);

/* Map validation extras - cub3d_map_validator_extra.c */
void	set_player(t_val_cubfile *cubfile, char c, int x, int y);
bool	val_find_player(t_val_cubfile *cubfile);

/* Color validation functions - cub3d_color_validator.c */
bool	val_check_rgb_values(int r, int g, int b, t_val_cubfile *cubfile);
int	    val_count_commas(const char *str);
int	    val_check_color_id(char id, t_val_cubfile *cubfile);
bool	val_check_color_format(char *color_str, t_val_cubfile *cubfile);
bool	val_check_color_values(char *color_str, t_val_cubfile *cubfile);

/* Color validation extras - cub3d_color_validator_extra.c */
bool	val_parse_color_start(char *line, char *id, char **color_str);
bool	val_extract_rgb(int color_index, char *color_str, t_val_cubfile *cubfile);

/* Utility functions - cub3d_utils.c */
char	*val_read_line(int fd);
bool	val_is_position_wall(int x, int y, t_val_cubfile *cubfile);
bool	val_is_position_empty(int x, int y, t_val_cubfile *cubfile);
bool	val_is_position_player(int x, int y, t_val_cubfile *cubfile);

/* Integration function - validator_integration.c */
int     validate_map_file(const char *filepath);

#endif