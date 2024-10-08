/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:13:40 by keramos-          #+#    #+#             */
/*   Updated: 2024/10/03 16:41:26 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
 * Structure for the game
 * map: the map
 */
typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
	t_imgs	*imgs;
}			t_game;

#endif
