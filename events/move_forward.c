/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:49:16 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/17 15:29:07 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(int map[25][25], t_mlx *mlx)
{
	if (map[(int)(mlx->cam_posx + mlx->cam_dirx * mlx->spw)]\
		[(int)(mlx->cam_posy)] == 0)
		mlx->cam_posx += mlx->cam_dirx * mlx->spw;
	if (map[(int)(mlx->cam_posx)]\
		[(int)(mlx->cam_posy + mlx->cam_diry * mlx->spw)] == 0)
		mlx->cam_posy += mlx->cam_diry * mlx->spw;
}
