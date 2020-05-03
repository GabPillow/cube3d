/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:04:45 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/03 15:46:41 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_right(t_data *data)
{
	int	a;
	int	b;

	a = (int)(data->posx + data->planex * SPW);
	b = (int)data->posy;
	if (data->map[a][b] == '0')
		data->posx += data->planex * SPW;
	a = (int)data->posx;
	b = (int)(data->posy + data->planey * SPW);
	if (data->map[a][b] == '0')
		data->posy += data->planey * SPW;
}
