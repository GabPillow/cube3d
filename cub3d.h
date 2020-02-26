/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:37:17 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/26 17:25:49 by grochefo         ###   ########.fr       */
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

# define K_S 1
# define K_W 13
# define K_A 0
# define K_D 2
# define K_ARRL 123
# define K_ARRR 124
# define SPW 0.15
# define SPT 0.15

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

typedef	struct	s_clc
{
	double		deltadistx;
	double		deltadisty;
	double		dirx;
	double		diry;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	double		camerax;
	double		perpwalldist;
	int			hline;
	int			side;
	int			mapx;
	int			mapy;
	int			color;
}				t_clc;

typedef struct	s_data
{
	char		**map;
	int			map_w;
	int			map_h;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			wd_h;
	int			wd_w;
	void		*mlx;
	void		*window;
	t_img		img;
}				t_data;


void	move_forward(t_data *data);
void	move_back(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	turning_cam(t_data *data, double speed);
void	ft_put_image(t_data *data);
void	ft_raycasting(t_data *data, t_img *img);
void	parsing_data(char *path, t_data *data);
void	line_to_tab(char *line, t_data *data);
void	init_data(char *map, t_data *data);
#endif