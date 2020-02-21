/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:44:33 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 17:34:26 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data_map(char *map, t_data *data)
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
	data->diry = 0.001;
	data->planex = 0;
	data->planey = 1;
}
