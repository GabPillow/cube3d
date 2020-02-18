/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:02:29 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/18 17:53:12 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calcul_vec_dist(t_ray *ray, int mapx, int mapy)
{
	ray->deltadistx = fabs(1 / ray->dirx);
	ray->deltadisty = fabs(1 / ray->diry);
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

static void	ft_calcul_wall(t_mlx *mlx, t_ray *ray, int map[25][25])
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			mlx->mapx += ray->stepx;
			mlx->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			mlx->mapy += ray->stepy;
			mlx->side = 1;
		}
		if (map[mlx->mapx][mlx->mapy] > 0)
			hit = 1;
	}
	if (mlx->side == 0)
		mlx->perpwalldist = fabs((mlx->mapx - ray->posx + (1 - ray->stepx) / 2) / ray->dirx);
	else
		mlx->perpwalldist = fabs((mlx->mapy - ray->posy + (1 - ray->stepy) / 2) / ray->diry);
}

void	ft_raycasting(t_mlx *mlx, int map[25][25])
{
	t_ray	ray;
	t_img	img;
	int		x;
	int		y;
	int		drawst;
	int		drawend;
	img.img_ptr = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	img.data = (int*)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	x = 0;
	y = 0;
	while (x < mlx->width)
	{
		mlx->camerax = 2 * x / (double)(mlx->width) - 1;
		ray.posx = mlx->cam_posx;
		ray.posy = mlx->cam_posy;
		ray.dirx = mlx->cam_dirx + mlx->planex * mlx->camerax;
		ray.diry = mlx->cam_diry + mlx->planey * mlx->camerax;
		mlx->mapx = (int)ray.posx;
		mlx->mapy = (int)ray.posy;
		ft_calcul_vec_dist(&ray, mlx->mapx, mlx->mapy);
		ft_calcul_wall(mlx, &ray, map);
		mlx->hline = (int)(mlx->height / mlx->perpwalldist);
		drawst = -mlx->hline / 2 + mlx->height / 2;
		drawend = mlx->hline / 2 + mlx->height / 2;
		drawst < 0 ? drawst = 0 : drawst;
		drawend >= mlx->height ? drawend = mlx->height - 1 : drawend;
		y = -mlx->height;
		while (y < mlx->height)
		{
			if (y < drawst)
				img.data[y * mlx->width + x] = 16747640;
			if (y >= drawst && y <= drawend)
			{
				mlx->color = 8558335;
				if (mlx->side == 1)
					mlx->color = 7247615;
				img.data[y * mlx->width + x] = mlx->color;
			}
			if (y > drawend)
				img.data[y * mlx->width + x] = 16737400;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, img.img_ptr, 0, 0);
}
