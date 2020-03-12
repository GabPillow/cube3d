/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:02:29 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/12 15:45:59 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_img(t_clc *clc, t_data *data, t_txt *txt, t_img *img)
{
	int	y;
	int	yt;
	int	drawst;
	int	drawend;

	drawst = -clc->hline / 2 + data->wd_h / 2;
	drawend = clc->hline / 2 + data->wd_h / 2;
	drawst < 0 ? drawst = 0 : drawst;
	drawend >= data->wd_h ? drawend = data->wd_h - 1 : drawend;
	y = 0;
	while (y < data->wd_h)
	{
		if (y < drawst)
			img->data[y * data->wd_w + clc->x] = 16747640;
		if (y >= drawst && y <= drawend)
		{
			yt = (y * 2 - data->wd_h + clc->hline) * (txt->height / 2) \
			/ clc->hline;
			img->data[y * data->wd_w + clc->x] = txt->data[yt * txt->width + \
			clc->xt];
		}
		if (y > drawend)
			img->data[y * data->wd_w + clc->x] = 16737400;
		y++;
	}
}

static void	ft_calcul_text(t_clc *clc, t_data *data, t_txt *txt)
{
	if (clc->side < 0)
		clc->wallx = data->posx + ((clc->mapy - data->posy + \
		(1 - clc->stepy) / 2) / clc->diry) * clc->dirx;
	else
		clc->wallx = data->posy + ((clc->mapx - data->posx + \
		(1 - clc->stepx) / 2) / clc->dirx) * clc->diry;
	clc->wallx -= floor((clc->wallx));
	clc->xt = (int)(clc->wallx * txt->width);
	if ((clc->side > 0 && clc->dirx > 0) || \
	(clc->side < 0 && clc->diry < 0))
		clc->xt = txt->width - clc->xt - 1;
	clc->hline = (int)(data->wd_h / clc->perpwalldist);
	ft_draw_img(clc, data, txt, &data->img);
}

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
			clc->side = clc->dirx < 0 ? NORTH : SOUTH;
		}
		else
		{
			clc->sidedisty += clc->deltadisty;
			clc->mapy += clc->stepy;
			clc->side = clc->diry < 0 ? WEST : EAST;
		}
		if (data->map[clc->mapx][clc->mapy] != '0')
			hit = 1;
	}
}

void	ft_raycasting(t_data *data, t_alltxt *list)
{
	t_clc		clc;

	clc.x = 0;
	while (clc.x < data->wd_w)
	{
		clc.camerax = 2 * clc.x / (double)(data->wd_h) - 1;
		clc.dirx = data->dirx + data->planex * clc.camerax;
		clc.diry = data->diry + data->planey * clc.camerax;
		clc.mapx = (int)data->posx;
		clc.mapy = (int)data->posy;
		ft_calcul_vec_dist(&clc, data);
		ft_calcul_wall(&clc, data);
		if (clc.side > 0)
			clc.perpwalldist = fabs((clc.mapx - data->posx + (1 - clc.stepx) / 2) / clc.dirx);
		else
			clc.perpwalldist = fabs((clc.mapy - data->posy + (1 - clc.stepy) / 2) / clc.diry);
		if (clc.side == NORTH)
			ft_calcul_text(&clc, data, &list->north);
		if (clc.side == SOUTH)
			ft_calcul_text(&clc, data, &list->south);
		if (clc.side == EAST)
			ft_calcul_text(&clc, data, &list->east);
		if (clc.side == WEST)
			ft_calcul_text(&clc, data, &list->west);
		clc.x++;
	}
}
