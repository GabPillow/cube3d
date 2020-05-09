/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:49:18 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/09 17:01:42 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_image(t_data *data)
{
	double *zbuffer;

	zbuffer = (double*)malloc(sizeof(double) * data->wd_w);
	ft_raycasting(data, &data->list, zbuffer);
	if (data->nbsprite)
		ft_raycasting_sprite(data, data->tab_sprite, data->list.sprite,\
		 zbuffer);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_ptr, 0, 0);
}
