/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:11:50 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 17:20:01 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	turning_cam(t_data *data, double speed)
{
	double	olddirx;
	double	olddplanex;

	olddirx = data->dirx;
	data->dirx = data->dirx * cos(speed) - data->diry * sin(speed);
	data->diry = olddirx * sin(speed) + data->diry * cos(speed);
	olddplanex = data->planex;
	data->planex = data->planex * cos(speed) - data->planey * sin(speed);
	data->planey = olddplanex * sin(speed) + data->planey * cos(speed);
}
