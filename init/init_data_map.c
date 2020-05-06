/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:44:33 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/06 19:25:33 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_h)
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] != ' ' && data->map[y][x] != '0' && \
			data->map[y][x] != '1' && data->map[y][x] != '2' &&\
			data->map[y][x] != 'N' && data->map[y][x] != 'S' &&\
			data->map[y][x] != 'E' && data->map[y][x] != 'W')
				ft_error(data, "Wrong caracter in map");
			if ((data->map[y][x] != ' ' && data->map[y][x] != '1')\
			&& (y == 0 || y == data->map_h \
			|| x == 0 || x == data->map_w))
				ft_error(data, "Map not closed");
			if (data->map[y][x] == ' ' && (data->map[y][x + 1] != ' ' ||\
			data->map[y][x + 1] != '1' || data->map[y + 1][x] != ' ' || \
			data->map[y + 1][x] != '1'))
				ft_error(data, "Map not closed");
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' ||\
			data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				init_position(data->map[y][x], x, y, data);
				data->map[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (data->posx == 0)
		ft_error(data, "Position missing");
}
