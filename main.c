/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:44:37 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/15 17:25:39 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

static int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
		mlx_pixel_put(mlx->mlx, mlx->window, 500, 500, 14481970);
	// if (keycode == 125)
	// 	mlx->y += 1;
	// if (keycode == 123)
	// 	mlx->x -= 1;
	// if (keycode == 124)
	// 	mlx->x += 1;
	mlx_pixel_put(mlx->mlx, mlx->window, 500, 502, 14481970);
	return (0);
}

int		main()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 1000, 1000, "test");
	mlx_hook(mlx.window, 2, 0, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
