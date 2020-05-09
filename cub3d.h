/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:37:17 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/09 16:58:37 by suzie            ###   ########.fr       */
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

# define NORTH 1
# define SOUTH 2
# define EAST -1
# define WEST -2
# define K_ESC 65307
# define K_Z 122
# define K_Q 113
# define K_S 115
# define K_D 100
# define K_ARRL 65361
# define K_ARRR 65363
# define SPW 0.15
# define SPT 0.15

typedef struct	s_txt
{
	void		*id;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_txt;

typedef struct 	s_sprite
{
	double x;
	double y;
}				t_sprite;

typedef struct	s_alltxt
{
	t_txt		south;
	t_txt		north;
	t_txt		east;
	t_txt		west;
	t_txt		sprite;
	int			floor;
	int			ceiling;
}				t_alltxt;

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
	int			xt;
	int			x;
	double		wallx;
}				t_clc;

typedef struct		s_data
{
	char			**map;
	t_sprite		*tab_sprite;
	int				map_h;
	int				map_w;
	int				nbsprite;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				wd_h;
	int				wd_w;
	void			*mlx;
	void			*window;
	t_img			img;
	t_alltxt		list;
}					t_data;

int		event(int keycode, t_data *data);
void	ft_close_window(t_data *data);
void	move_forward(t_data *data);
void	move_back(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	turning_cam(t_data *data, double speed);

int	    init_color(t_data *data, char *line);
void	init_data_map(t_data *data);
void    init_position(char p, int x, int y, t_data *data);
void	init_resolution(t_data *data, char *line);
void	init_sprite(t_data *data);
void    init_texture(t_data *data, t_txt *txt, char *line);
void    init_to_default(t_data *data);

void	line_to_tab(char *line, t_data *data);
void	parsing_data(char *path, t_data *data);

void	ft_calcul_vec_dist(t_clc *clc, t_data *data);
void	ft_calcul_wall(t_clc *clc, t_data *data);
void    ft_raycasting_sprite(t_data *data, t_sprite *tab_sprite, t_txt txtsp,
double *zbuffer);
void	ft_raycasting(t_data *data, t_alltxt *list, double *zbuffer);

void    ft_error(t_data *data, char *s);
void	ft_exit_cub(t_data *data);
void	ft_put_image(t_data *data);
#endif
