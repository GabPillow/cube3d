/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:42:19 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/05 16:53:07 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		line_to_tab(char *line, t_data *data)
{
	int	i;
	int	b;
	int a;

	a = 0;
	b = 8;
	i = 8;
	data->map = (char**)ft_calloc(data->map_h, sizeof(char*));
	while (line[i])
	{
		if (line[i] == '|')
		{
			data->map[a] = ft_strndup(line + i - b, b);
			b = 0;
			i++;
			a++;
		}
		i++;
		b++;
	}
	ft_strdel(&line);
}
