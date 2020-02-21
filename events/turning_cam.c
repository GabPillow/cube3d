/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:11:50 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 16:03:12 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	turning_cam(t_mlx *mlx, t_map *map, double speed)
{
	double	olddirx;
	double	olddplanex;

	olddirx = map->dirx;
	map->dirx = map->dirx * cos(speed) - map->diry * sin(speed);
	map->diry = olddirx * sin(speed) + map->diry * cos(speed);
	olddplanex = mlx->planex;
	mlx->planex = mlx->planex * cos(speed) - mlx->planey * sin(speed);
	mlx->planey = olddplanex * sin(speed) + mlx->planey * cos(speed);
}
