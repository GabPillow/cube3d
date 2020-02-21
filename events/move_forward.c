/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:49:16 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 17:15:58 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_data *data)
{
	int a;
	int	b;

	a = (int)(data->posx + data->dirx * SPW);
	b = (int)data->posy;
	if ((a >= 0 && a <= data->map_h) && (b >= 0 && b <= data->map_w) \
	&& data->map[a][b] == '0')
		data->posx += data->dirx * SPW;
	a = (int)data->posx;
	b = (int)(data->posy + data->diry * SPW);
	if ((a >= 0 && a <= data->map_h) && (b >= 0 && b <= data->map_w) \
	&& data->map[a][b] == '0')
		data->posy += data->diry * SPW;
}