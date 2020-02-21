/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:21:39 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 13:27:53 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(t_map *map, t_mlx *mlx)
{
	int a;
	int	b;

	a = (int)(mlx->cam_posx - mlx->planex * mlx->spw);
	b = (int)mlx->cam_posy;
	if ((a >= 0 && a <= map->size_h) && (b >= 0 && b <= map->size_w) && \
	map->map[a][b] == '0')
		mlx->cam_posx -= mlx->planex * mlx->spw;
	a = (int)mlx->cam_posx;
	b = (int)(mlx->cam_posy - mlx->planey * mlx->spw);
	if ((a >= 0 && a <= map->size_h) && (b >= 0 && b <= map->size_w) && \
	map->map[a][b] == '0')
		mlx->cam_posy -= mlx->planey * mlx->spw;
}
