/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:37:17 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/15 19:03:36 by grochefo         ###   ########.fr       */
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

#endif