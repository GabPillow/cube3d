/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:44:33 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/26 12:26:16 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data(char *map, t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i] && (map[i] == '1' || map[i] == '0'))
	{
		if (x == data->map_w)
		{
			x = 0;
			y++;
		}
		x++;
		i++;
	}
	map[i] = '0';
	data->posx = x + 0.5;
	data->posy = y + 0.5;
	data->dirx = -1;
	data->diry = 0.00001;
	data->planex = 0;
	data->planey = 1;
	data->wd_h = 800;
	data->wd_w = 1000;

	//SOUTH
	// data->dirx = 1;
	// data->diry = -0.001;
	// data->planex = 0;
	// data->planey = -1;

	//NORTH
	// data->dirx = -1;
	// data->diry = 0.001;
	// data->planex = 0;
	// data->planey = 1;

	// EAST
	// data->dirx = -0.0001;
	// data->diry = 1;
	// data->planex = 1;
	// data->planey = 0;

	//WEST
	// data->dirx = 0.0001;
	// data->diry = -1;
	// data->planex = -1;
	// data->planey = 0;
}
