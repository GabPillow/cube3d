/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:41:40 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 17:33:49 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		parsing_map(char *path, t_data *data)
{
	int			fd;
	char		*line;
	char		*tab;

	data->map = NULL;
	tab = NULL;
	fd = open(path, O_RDONLY);
	data->map_h = get_next_line(fd, &line);
	data->map_w = (int)ft_strlen(line);
	tab = ft_strjoinplus(tab, line, 3);
	while (get_next_line(fd, &line))
	{
		data->map_h++;
		tab = ft_strjoinplus(tab, line, 3);
	}
	init_data_map(tab, data);
	data->map = ft_calloc(data->map_h, sizeof(char*));
	line_to_tab(tab, data);
}
