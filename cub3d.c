/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:58:36 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/05 18:58:24 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = ft_strlen(argv[1]) - 1;
	if (argc == 2)
	{
		init_to_default(&data);
		if (ft_strlen(argv[1]) < 4 || \
		argv[1][i] != 'b' || argv[1][i - 1] != 'u' || \
		argv[1][i - 2] != 'c' || argv[1][i - 3] != '.')
			ft_error(&data, "Configuration file must be .cub");
		data.mlx = mlx_init();
		parsing_data(argv[1], &data);
		// data.window = mlx_new_window(data.mlx, data.wd_w, data.wd_h, "test");
		// data.img.img_ptr = mlx_new_image(data.mlx, data.wd_w, data.wd_h);
		// ft_put_image(&data);
		// mlx_hook(data.window, 2, 1L << 0, event, &data);
		// mlx_loop(data.mlx);
		return (1);
	}
	write(2, "No configuration file\n", 23);
}
