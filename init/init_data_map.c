/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:44:33 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/01 17:59:58 by suzie            ###   ########.fr       */
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
	while (map[i])
	{
		if (map[i] != ' ' || map[i] != '0' || map[i] != '1' || map[i] != '2')
			init_position(map[i], x, y, data);
		if (map[i] == ' ' && map[i + 1] != 1)
		if (x == data->map_w)
		{
			x = 0;
			y++;
		}
		x++;
		i++;
	}
	map[i] = '0';
}
