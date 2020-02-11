/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:37:17 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/11 18:36:10 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_DOWN = 125
# define KEY_UP = 126
# define KEY_LEFT = 123
# define KEY_RIGHT = 124

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef	struct	s_pixel
{
	int			hline;
	int			drawst;
	int			drawend;
	int			color;
}				t_pixel;

typedef struct	s_map
{
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
}				t_map;

typedef struct	s_cam
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			hit;
	int			side;
}				t_cam;

typedef struct	s_ray
{
	double		camerax;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
}				t_ray;

#endif