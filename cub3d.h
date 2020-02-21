/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:37:17 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 16:03:44 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"

# define K_S = 125
# define K_W = 126
# define K_A = 123
# define K_D = 124

typedef struct	s_map
{
	char		**map;
	char		dir;
	int			size_w;
	int			size_h;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
}				t_map;

typedef struct	s_texture
{
	void		*id;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_texture;

typedef	struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef	struct	s_ray
{
	double		deltadistx;
	double		deltadisty;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
}				t_ray;

typedef struct	s_mlx
{
	t_map		map;
	int			height;
	int			width;
	double		spw;
	void		*mlx;
	void		*window;
	int			hline;
	int			color;
	int			mapx;
	int			mapy;
	double		planex;
	double		planey;
	int			side;
	double		camerax;
	double		perpwalldist;
}				t_mlx;

void	move_forward(t_map *map, t_mlx *mlx);
void	move_back(t_map *map, t_mlx *mlx);
void	move_right(t_map *map, t_mlx *mlx);
void	move_left(t_map *map, t_mlx *mlx);
void	turning_cam(t_mlx *mlx, t_map *map, double speed);
void	ft_raycasting(t_mlx *mlx, t_map *map);
void	parsing_map(char *path, t_map *map);
void	line_to_tab(char *line, t_map *map);
void	init_data_map(char *map, t_map *data);
#endif