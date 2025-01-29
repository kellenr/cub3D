/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:13:40 by keramos-          #+#    #+#             */
/*   Updated: 2025/01/29 20:46:00 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* Paths */
typedef enum e_paths
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	SPRITE,
}			t_paths;
/*
 * Structure for the player
 * x: the x position of the player
 * y: the y position of the player
 * dir_x: the x direction of the player
 * dir_y: the y direction of the player
 * angle: the angle the player is facing
 * direction: the direction the player is facing
 */
typedef struct s_player
{
	double	x;			// Player's X position on the map
	double	y;			// Player's Y position on the map
	double	dir_x;		// X component of the direction vector
	double	dir_y;		// Y component of the direction vector
	double	plane_x;	// X component of the plane vector
	double	plane_y;	// Y component of the plane vector
	double	angle;		// Player's viewing angle
	int		move_x;		// Player's movement in X direction
	int		move_y;		// Player's movement in Y direction
	char	di;	// Player's viewing direction
}			t_player;

/*
 * Structure for the map
 * map: the map itself
 * width: the width of the map
 * height: the height of the map
 */
typedef struct s_map
{
	char	**map_data;
	int		width;
	int		height;

}			t_map;

/*
 * Structure for the image
 * img: the image
 * pix: the pixel data
 * bitp: bits per pixel
 * ln_len: line length
 * endian: endian
 */
typedef struct s_imgs
{
	void	*img;
	char	*pix;
	int		bitp;
	int		ln_len;
	int		endian;
	// void	*intro_img;      // Add this line
	// char	*intro_pix;      // And this if you need pixel data
	// int		intro_bitp;
	// int		intro_ln_len;
	// int		intro_endian;
}			t_imgs;

typedef struct s_keys
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	rotate_left;
	int	rotate_right;
}		t_keys;

/*
 * Structure for the textures
 * north: the north texture
 * south: the south texture
 * west: the west texture
 * east: the east texture
 * sprite: the sprite texture
 * floor_color: the floor color
 * ceiling_color: the ceiling color
 */
typedef struct s_txt
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*door;
	int		floor_color;
	int		ceiling_color;
	t_imgs	no;
	t_imgs	so;
	t_imgs	we;
	t_imgs	ea;
	t_imgs	door_img;
	int		bitp;
	int		size;
	int		index;
	double	step;
	double	tex_pos;
	int		x;
	int		y;

}			t_txt;


typedef struct s_door
{
	int		x;
	int		y;
	int		open; // 0 = Closed, 1 = Opening, 2 = Open
	double	timer;
}			t_door;



/*
 * Structure for the ray
 * camera_x: Camera space X coordinate (-1 to 1 for screen width)
 * ray_dir_x: Direction vector X for the current ray
 * ray_dir_y: Direction vector y for the current ray
 * map_x: Current square in the map (X coordinate)
 * map_y: Current square in the map (y coordinate)
 * side_dist_x: Distance to the next vertical grid line
 * side_dist_y: Distance to the next horizontal grid line
 * delta_dist_x: Distance between two vertical grid lines
 * delta_dist_y: Distance between two horizontal grid lines
 * perp_wall_dist: Perpendicular distance to the wall
 * step_x: Direction to step in X (-1 or 1)
 * step_y: Direction to step in Y (-1 or 1)
 * hit: Was a wall hit? (1 if yes)
 * side: Was the wall hit vertical or horizontal?
 */
typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	char 	*wall;
}			t_ray;

/*
 * Structure for the game
 * map: the map
 * mlx: the mlx
 * imgs: the images
 * player: the player
 * txt: the textures
 * intro_active: the intro screen active
 */
typedef struct s_game
{
	t_map		*map;
	void		*mlx;
	void		*win;
	t_imgs		imgs;
	t_player	player;
	t_txt		txt;
	t_ray		ray;
	t_keys		keys;
	int			**txt_data;
	int			**txt_pix;
	int			intro_active;
	int			mini_active;
}			t_game;

#endif
