/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:42:19 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/03 18:26:12 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		line_to_tab(char *line, t_data *data)
{
	int	i;
	int	b;

	b = 0;
	i = 0;
	data->map = ft_calloc(data->map_h, sizeof(char*));
	while (line[i])
	{
		if (line[i] == '|')
		{
			ft_strndup(line + i - b, b);
			b = 0;
		}
		i++;
		b++;
	}
	ft_strdel(&line);
}
