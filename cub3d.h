/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:37:17 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/17 15:31:48 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>

# define KEY_DOWN = 125
# define KEY_UP = 126
# define KEY_LEFT = 123
# define KEY_RIGHT = 124

typedef struct	s_texture
{
	void	*id;
	int		width;
	int		height;
}				t_texture;

typedef struct	s_mlx
{
	double		spw;
	void		*mlx;
	void		*window;
	int			hline;
	int			drawst;
	int			drawend;
	int			color;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	double		cam_posx;
	double		cam_posy;
	double		cam_dirx;
	double		cam_diry;
	double		planex;
	double		planey;
	int			hit;
	int			side;
	double		camerax;
	double		ray_posx;
	double		ray_posy;
	double		ray_dirx;
	double		ray_diry;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
}				t_mlx;

void	move_forward(int map[25][25], t_mlx *mlx);
void	move_back(int map[25][25], t_mlx *mlx);
void	move_right(int map[25][25], t_mlx *mlx);
void	move_left(int map[25][25], t_mlx *mlx);
void	turning_cam(t_mlx *mlx, double speed);
#endif