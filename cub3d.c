/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:58:36 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 16:11:59 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		event(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		move_forward(&mlx->map, mlx);
	else if (keycode == 1)
		move_back(&mlx->map, mlx);
	else if (keycode == 0)
		move_left(&mlx->map, mlx);
	else if (keycode == 2)
		move_right(&mlx->map, mlx);
	else if (keycode == 123 || keycode == 124)
		turning_cam(mlx, &mlx->map, keycode == 123 ? 0.15 : -0.15);
	else
		return (0);
	ft_raycasting(mlx, &mlx->map);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.height = 800;
	mlx.width = 1000;
	mlx.spw = 0.15;
	mlx.planex = 0;
	mlx.planey = 1;
	if (argc == 2)
	{
		parsing_map(argv[1], &mlx.map);
		mlx.mlx = mlx_init();
		mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "test");
		ft_raycasting(&mlx, &mlx.map);
		mlx_hook(mlx.window, 2, 0, event, &mlx);
		mlx_loop(mlx.mlx);
		return (1);
	}
	write(1, "NO MAP YOU FUCKING IDIOT", 24);
}
