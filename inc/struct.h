/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:13:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/11/03 21:56:07 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	// float	x;
	// float	y;
	// float	dir_x;
	// float	dir_y;
	// float	angle;
	// char		direction;
	double	x;        // Player's X position on the map
	double	y;        // Player's Y position on the map
	double	dir_x;    // X component of the direction vector
	double	dir_y;    // Y component of the direction vector
	double	plane_x;  // X component of the plane vector
	double	plane_y;  // Y component of the plane vector
	double	angle;    // Player's viewing angle
	char	direction;  // Player's viewing direction
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
	void	*intro_img;      // Add this line
	char	*intro_pix;      // And this if you need pixel data
	int		intro_bitp;
	int		intro_ln_len;
	int		intro_endian;
}			t_imgs;

/*
 * Structure for the mlx
 * mlx: the mlx pointer
 * win: the window pointer
 */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*bg_image; // Add this line
}			t_mlx;

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
	int		floor_color;
	int		ceiling_color;
}			t_txt;

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
	t_mlx		*mlx;
	t_imgs		*imgs;
	t_player	*player;
	t_txt		*txt;
	int			intro_active;
}			t_game;

#endif
