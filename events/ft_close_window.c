/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:57:59 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/12 16:08:32 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_close_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
}
