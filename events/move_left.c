/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:21:39 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/17 17:02:48 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(int map[25][25], t_mlx *mlx)
{
	if (map[(int)(mlx->cam_posx - mlx->planex * mlx->spw)]\
		[(int)(mlx->cam_posy)] == 0)
		mlx->cam_posx -= mlx->planex * mlx->spw;
	if (map[(int)(mlx->cam_posx)]\
		[(int)(mlx->cam_posy - mlx->planey * mlx->spw)] == 0)
		mlx->cam_posy -= mlx->planey * mlx->spw;
}
