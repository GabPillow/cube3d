/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:44:37 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/17 14:24:15 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

typedef struct	s_texture
{
	int		width;
	int		height;
}				t_texture;

// static int		key_hook(int keycode, t_mlx *mlx)
// {
// 	if (keycode == 126)
// 		mlx_pixel_put(mlx->mlx, mlx->window, 500, 500, 14481970);
// 	// if (keycode == 125)
// 	// 	mlx->y += 1;
// 	// if (keycode == 123)
// 	// 	mlx->x -= 1;
// 	// if (keycode == 124)
// 	// 	mlx->x += 1;
// 	mlx_pixel_put(mlx->mlx, mlx->window, 500, 502, 14481970);
// 	return (0);
// }

int		main()
{
	t_mlx	mlx;
	t_texture test;
	void		*img;
	test.width = 32;
	test.height = 32;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 1000, 1000, "test");
	img = mlx_xpm_file_to_image ( mlx.mlx, "wood.xpm", &test.width , &test.height);
	mlx_put_image_to_window ( mlx.mlx, mlx.window, img, 0, 0);

	// mlx_hook(mlx.window, 2, 0, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
