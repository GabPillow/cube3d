/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:51:37 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/05 14:18:15 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_exit_cub(t_data *data)
{
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	// if (data->img.img_ptr)
	// 	mlx_destroy_image(data->mlx, data->img.img_ptr);
	// if (data->list.east.id)
	// 	mlx_destroy_image(data->mlx, data->list.east.id);
	// if (data->list.west.id)
	// 	mlx_destroy_image(data->mlx, data->list.west.id);
	// if (data->list.north.id)
	// 	mlx_destroy_image(data->mlx, data->list.north.id);
	// if (data->list.south.id)
	// 	mlx_destroy_image(data->mlx, data->list.south.id);
	exit(1);
}
