/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_vec_dist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:07:32 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/12 17:08:56 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calcul_vec_dist(t_clc *clc, t_data *data)
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
