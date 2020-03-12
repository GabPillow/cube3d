/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:04:59 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/12 17:05:38 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calcul_wall(t_clc *clc, t_data *data)
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
