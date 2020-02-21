/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:49:16 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:09 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_map *map, t_mlx *mlx)
{
	int a;
	int	b;

	a = (int)(map->posx + map->dirx * mlx->spw);
	b = (int)map->posy;
	if ((a >= 0 && a <= map->size_h) && (b >= 0 && b <= map->size_w) \
	&& map->map[a][b] == '0')
		map->posx += map->dirx * mlx->spw;
	a = (int)map->posx;
	b = (int)(map->posy + map->diry * mlx->spw);
	if ((a >= 0 && a <= map->size_h) && (b >= 0 && b <= map->size_w) \
	&& map->map[a][b] == '0')
		map->posy += map->diry * mlx->spw;
}
