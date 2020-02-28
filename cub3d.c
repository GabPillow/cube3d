/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:58:36 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/28 17:04:32 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		event(int keycode, t_data *data)
{
	if (keycode == K_W)
		move_forward(data);
	else if (keycode == K_S)
		move_back(data);
	else if (keycode == K_A)
		move_left(data);
	else if (keycode == K_D)
		move_right(data);
	else if (keycode == K_ARRL || keycode == K_ARRR)
		turning_cam(data, keycode == K_ARRL ? SPT : -SPT);
	else
		return (0);
	ft_put_image(data);
	return (0);
}

int				main(int argc, char **argv)
{
	t_data	data;

	data.text.width = 32;
	data.text.height = 32;
	if (argc == 2)
	{
		parsing_data(argv[1], &data);
		data.mlx = mlx_init();
		data.window = mlx_new_window(data.mlx, data.wd_w, data.wd_h, "test");
		data.img.img_ptr = mlx_new_image(data.mlx, data.wd_w, data.wd_h);
		data.img.data = \
		(int*)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.size_l, &data.img.endian);
		data.text.id  = mlx_xpm_file_to_image(data.mlx, "wood.xpm", &data.text.height, &data.text.width);
		data.text.data = (int*)mlx_get_data_addr(data.text.id, &data.text.bpp, &data.text.size_l, &data.text.endian);
		ft_put_image(&data);
		mlx_hook(data.window, 2, 0, event, &data);
		mlx_loop(data.mlx);
		return (1);
	}
	write(1, "NO MAP YOU FUCKING IDIOT", 24);
}
