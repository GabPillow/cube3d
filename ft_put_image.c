/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:49:18 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/10 17:45:09 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_image(t_data *data)
{
	ft_raycasting(data, &data->list);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_ptr, 0, 0);
}
