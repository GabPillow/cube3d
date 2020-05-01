/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:58:36 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/01 16:17:15 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		init_to_default(&data);
		parsing_data(argv[1], &data);
		data.mlx = mlx_init();
		data.window = mlx_new_window(data.mlx, data.wd_w, data.wd_h, "test");
		data.img.img_ptr = mlx_new_image(data.mlx, data.wd_w, data.wd_h);
		data.img.data = \
		(int*)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.size_l, &data.img.endian);
		data.list.north.id  = mlx_xpm_file_to_image(data.mlx, "textures/wood.xpm", &data.list.north.height, &data.list.north.width);
		data.list.north.data = (int*)mlx_get_data_addr(data.list.north.id, &data.list.north.bpp, &data.list.north.size_l, &data.list.north.endian);
		data.list.south.id  = mlx_xpm_file_to_image(data.mlx, "textures/rainbow.xpm", &data.list.south.height, &data.list.south.width);
		data.list.south.data = (int*)mlx_get_data_addr(data.list.south.id, &data.list.south.bpp, &data.list.south.size_l, &data.list.south.endian);
		data.list.east.id  = mlx_xpm_file_to_image(data.mlx, "textures/tiger.xpm", &data.list.east.height, &data.list.east.width);
		data.list.east.data = (int*)mlx_get_data_addr(data.list.east.id, &data.list.east.bpp, &data.list.east.size_l, &data.list.east.endian);
		data.list.west.id  = mlx_xpm_file_to_image(data.mlx, "textures/wall.XPM", &data.list.west.height, &data.list.west.width);
		data.list.west.data = (int*)mlx_get_data_addr(data.list.west.id, &data.list.west.bpp, &data.list.west.size_l, &data.list.west.endian);
		ft_put_image(&data);
		mlx_hook(data.window, 2, 1L << 0, event, &data);
		mlx_loop(data.mlx);
		return (1);
	}
	write(1, "NO MAP YOU FUCKING IDIOT", 24);
}
