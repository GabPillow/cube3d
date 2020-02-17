/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:11:50 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/17 17:48:40 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	turning_cam(t_mlx *mlx, double speed)
{
	double	olddirx;
	double	olddplanex;

	olddirx = mlx->cam_dirx;
	mlx->cam_dirx = mlx->cam_dirx * cos(-speed) - mlx->cam_diry * sin(-speed);
	mlx->cam_diry = olddirx * sin(-speed) + mlx->cam_diry * cos(-speed);
	olddplanex = mlx->planex;
	mlx->planex = mlx->planex * cos(-speed) - mlx->planey * sin(-speed);
	mlx->planey = olddplanex * sin(-speed) + mlx->planey * cos(-speed);
}
