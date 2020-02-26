/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:02:29 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/26 17:20:26 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calcul_vec_dist(t_clc *clc, t_data *data)
{
	clc->deltadistx = fabs(1 / clc->dirx);
	clc->deltadisty = fabs(1 / clc->diry);
	if (clc->dirx < 0)
	{
		clc->stepx = -1;
		clc->sidedistx = (data->posx - clc->mapx) * clc->deltadistx;
	}
	else
	{
		clc->stepx = 1;
		clc->sidedistx = (clc->mapx + 1.0 - data->posx) * clc->deltadistx;
	}
	if (clc->diry < 0)
	{
		clc->stepy = -1;
		clc->sidedisty = (data->posy - clc->mapy) * clc->deltadisty;
	}
	else
	{
		clc->stepy = 1;
		clc->sidedisty = (clc->mapy + 1.0 - data->posy) * clc->deltadisty;
	}
}

static void	ft_calcul_wall(t_clc *clc, t_data *data)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (clc->sidedistx < clc->sidedisty)
		{
			clc->sidedistx += clc->deltadistx;
			clc->mapx += clc->stepx;
			clc->side = 0;
		}
		else
		{
			clc->sidedisty += clc->deltadisty;
			clc->mapy += clc->stepy;
			clc->side = 1;
		}
		if (data->map[clc->mapx][clc->mapy] != '0')
			hit = 1;
	}
	if (clc->side == 0)
		clc->perpwalldist = fabs((clc->mapx - data->posx + (1 - clc->stepx) / 2) / clc->dirx);
	else
		clc->perpwalldist = fabs((clc->mapy - data->posy + (1 - clc->stepy) / 2) / clc->diry);
}

void	ft_raycasting(t_data *data, t_img *img)
{
	t_clc		clc;
	int			x;
	int			y;
	int			drawst;
	int			drawend;

	x = 0;
	y = 0;
	while (x < data->wd_w - 1)
	{
		clc.camerax = 2 * x / (double)(data->wd_h) - 1;
		clc.dirx = data->dirx + data->planex * clc.camerax;
		clc.diry = data->diry + data->planey * clc.camerax;
		clc.mapx = (int)data->posx;
		clc.mapy = (int)data->posy;
		ft_calcul_vec_dist(&clc, data);
		ft_calcul_wall(&clc, data);
		clc.hline = (int)(data->wd_h / clc.perpwalldist);
		drawst = -clc.hline / 2 + data->wd_h / 2;
		drawend = clc.hline / 2 + data->wd_h / 2;
		drawst < 0 ? drawst = 0 : drawst;
		drawend >= data->wd_h ? drawend = data->wd_h - 1 : drawend;
		y = -data->wd_h;
		while (y < data->wd_h - 1)
		{
			if (y < drawst)
				img->data[y * data->wd_w + x] = 16747640;
			if (y >= drawst && y <= drawend)
			{
				clc.color = 8558335;
				if (clc.side == 1)
					clc.color = 7247615;
				img->data[y * data->wd_w + x] = clc.color;
			}
			if (y > drawend)
				img->data[y * data->wd_w + x] = 16737400;
			y++;
		}
		x++;
	}
}
