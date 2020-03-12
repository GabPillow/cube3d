/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:51:37 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/12 16:58:27 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_cub(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_image(data->mlx, data->list.east.id);
	mlx_destroy_image(data->mlx, data->list.west.id);
	mlx_destroy_image(data->mlx, data->list.north.id);
	mlx_destroy_image(data->mlx, data->list.south.id);
	exit(1);
}
