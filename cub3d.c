/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:17:02 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/11 19:02:45 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>

int	main()
{
	int map[24][24] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
	t_cam	cam;
	t_ray	ray;
	t_mlx	mlx;
	t_map	pos;
	t_pixel pix;
	int		x;
	int		y;
	x  = 0;
	//def map
	//position camera
	cam.posx = 22;
	cam.posy = 11.5;
	//regard camera
	cam.dirx = -1;
	cam.diry = 0;
	//plan projection
	cam.planex = 0;
	cam.planey = 1;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 1000, 1000, "test");

	//rayon calculs

	while (x <= 1000)
	{
		ray.camerax = (2 * x / 1000 ) - 1;
		ray.posx = cam.posx;
		ray.posy = cam.posy;
		ray.dirx = cam.dirx + cam.planex * ray.camerax;
		ray.diry = cam.diry + cam.planex * ray.camerax;
		pos.mapx = (int)cam.posx;
		pos.mapy = (int)cam.posy;
		pos.deltadistx = fabs(1 / ray.dirx);
    	pos.deltadisty = fabs(1 / ray.diry);
		cam.hit = 0;
		if (ray.dirx < 0)
		{
			ray.stepx = -1;
			ray.sidedistx = (ray.posx - pos.mapx) * pos.deltadistx;
		}
		else
		{
			ray.stepx = 1;
			ray.sidedistx = (pos.mapx + 1.0 - ray.posx) * pos.deltadistx;
		}
		if (ray.diry < 0)
		{
			ray.stepy = -1;
			ray.sidedisty = (ray.posy - pos.mapy) * pos.deltadisty;
		}
		else
		{
			ray.stepy = 1;
			ray.sidedisty = (pos.mapy + 1.0 - ray.posy) * pos.deltadisty;
		}
		while (cam.hit == 0)
		{
			if (ray.sidedistx < ray.sidedisty)
			{
				ray.sidedistx += pos.deltadistx;
				pos.mapx += ray.stepx;
				cam.side = 0;
			}
			else
			{
				ray.sidedisty += pos.deltadisty;
				pos.mapy += ray.stepy;
				cam.side = 1;
			}
			if (map[pos.mapx][pos.mapy]>0)
				cam.hit = 1;
		}
		if (cam.side == 0)
			ray.perpwalldist = fabs((pos.mapx - ray.posx + (1 - ray.stepx) / 2) / ray.dirx);
		else
			ray.perpwalldist = fabs((pos.mapy - ray.posy + (1 - ray.stepy) / 2) / ray.diry);
		pix.hline = fabs(1000 / ray.perpwalldist);
		pix.drawst = (int)((pix.hline * -1) / 2 + 1000 / 2);
		pix.drawend = (int)(pix.hline / 2 + 1000 / 2);
		if (pix.drawst < 0)
			pix.drawst = 0;
		if (pix.drawend >= 1000)
			pix.drawend = 1000 - 1;
		y = pix.drawst;
		while (y < pix.drawend)
		{
			pix.color = 8558335;
			if (cam.side == 1)
				pix.color = 7247615;
			mlx_pixel_put(mlx.mlx, mlx.window, x, pix.drawst, pix.color);
			y++;
		}
		x++;
	}
	mlx_loop(mlx.mlx);
}