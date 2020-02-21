/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:58:36 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 17:20:55 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		event(int keycode, t_mlx *mlx)
{
	if (keycode == K_W)
		move_forward(&mlx->data);
	else if (keycode == K_S)
		move_back(&mlx->data);
	else if (keycode == K_A)
		move_left(&mlx->data);
	else if (keycode == K_D)
		move_right(&mlx->data);
	else if (keycode == K_ARRL || keycode == K_ARRR)
		turning_cam(&mlx->data, keycode == K_ARRL ? SPT : -SPT);
	else
		return (0);
	ft_raycasting(mlx, &mlx->data);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.height = 800;
	mlx.width = 1000;
	if (argc == 2)
	{
		parsing_data(argv[1], &mlx.data);
		mlx.mlx = mlx_init();
		mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "test");
		ft_raycasting(&mlx, &mlx.data);
		mlx_hook(mlx.window, 2, 0, event, &mlx);
		mlx_loop(mlx.mlx);
		return (1);
	}
	write(1, "NO data YOU FUCKING IDIOT", 24);
}
