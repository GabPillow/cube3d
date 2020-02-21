/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:42:19 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 19:09:20 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		line_to_tab(char *line, t_data *data)
{
	int	i;
	int	b;

	b = 0;
	i = 0;
	while (i < data->map_h)
	{
		data->map[i] = line + b;
		b += data->map_w;
		i++;
	}
}
