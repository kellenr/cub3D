/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:13:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/25 23:03:07 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
 * Structure for the player
 * x: the x position of the player
 * y: the y position of the player
 * angle: the angle the player is facing
 * direction: the direction the player is facing
 */
typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	char	direction;
} t_player;

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
 * textures: the textures
 */
typedef struct s_game
{
	t_map		*map;
	t_mlx		*mlx;
	t_imgs		*imgs;
	// t_imgs		intro;
	t_player	*player;
	t_txt		*txt;
}			t_game;

#endif
