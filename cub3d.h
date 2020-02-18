/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:37:17 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/18 14:36:53 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define K_S = 125
# define K_W = 126
# define K_A = 123
# define K_D = 124

typedef struct	s_texture
{
	void	*id;
	int		width;
	int		height;
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
	int			height;
	int			width;
	double		spw;
	void		*mlx;
	void		*window;
	int			hline;
	int			color;
	int			mapx;
	int			mapy;
	double		cam_posx;
	double		cam_posy;
	double		cam_dirx;
	double		cam_diry;
	double		planex;
	double		planey;
	int			side;
	double		camerax;
	double		perpwalldist;
}				t_mlx;

void	move_forward(int map[25][25], t_mlx *mlx);
void	move_back(int map[25][25], t_mlx *mlx);
void	move_right(int map[25][25], t_mlx *mlx);
void	move_left(int map[25][25], t_mlx *mlx);
void	turning_cam(t_mlx *mlx, double speed);
void	ft_raycasting(t_mlx *mlx, int map[25][25]);
#endif