/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:58:36 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/02 18:12:51 by suzie            ###   ########.fr       */
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
		ft_put_image(&data);
		mlx_hook(data.window, 2, 1L << 0, event, &data);
		mlx_loop(data.mlx);
		return (1);
	}
	write(1, "NO MAP YOU FUCKING IDIOT", 24);
}
