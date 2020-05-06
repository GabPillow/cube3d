/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:49:16 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/06 19:25:54 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_data *data)
{
	int a;
	int	b;

	a = (int)(data->posx + data->dirx * SPW);
	b = (int)data->posy;
	if (data->map[a][b] == '0')
		data->posx += data->dirx * SPW;
	a = (int)data->posx;
	b = (int)(data->posy + data->diry * SPW);
	if (data->map[a][b] == '0')
		data->posy += data->diry * SPW;
}
