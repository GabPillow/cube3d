/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:41:40 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/23 12:55:16 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		parsing_data(char *path, t_data *data)
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
	ft_strdel(&line);
	close(fd);
	init_data(tab, data);
	data->map = ft_calloc(data->map_h, sizeof(char*));
	line_to_tab(tab, data);
}
