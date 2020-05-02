/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:41:40 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/02 14:23:24 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void info_exist(t_data *data, char *line)
{
	int i;

	i = 0;
	if (data->wd_h == 0 || !&data->list.north || !&data->list.south \
	|| !&data->list.west || !&data->list.east || &data->list.floor == -1 \
	|| &data->list.ceiling == -1)
	{
		ft_strdel(&line);
		ft_error(data, "Missing params configuration file\n");
	}
	// !&data->list.sprite
}

static int check_line(t_data *data, char *line)
{
	if (line[0] == 'R')
		init_resolution(data, line);
	else if (line[0] == 'N' && line[1] == 'O')
		init_texture(data, data->list.north, line);
	else if (line[0] == 'S' && line[1] == 'O')
		init_texture(data, data->list.south, line);
	else if (line[0] == 'W' && line[1] == 'E')
		init_texture(data, data->list.west, line);
	else if (line[0] == 'E' && line[1] == 'A')
		init_texture(data, data->list.east, line);
	// else if (line[0] == 'S' && line[1] == ' ')
	// 	init_texture(data->list.sprite, line);
	else if (line[0] == 'F')
		init_color(data, data->list.floor, line);
	else if (line[0] == 'C')
		init_color(data, data->list.ceiling, line);
	else if (line)
		return(1);
	return (0);
}

void		parsing_data(char *path, t_data *data)
{
	int			fd;
	char		*line;

	while (get_next_line(fd, &line))
	{
		if (check_line(data, line))
			break;
		free(&line);
	}
	info_exist(data, line);
	// tab = NULL;
	// fd = open(path, O_RDONLY);
	// data->map_h = get_next_line(fd, &line);
	// data->map_w = (int)ft_strlen(line);
	// tab = ft_strjoinplus(tab, line, 3);
	// while (get_next_line(fd, &line))
	// {
	// 	data->map_h++;
	// 	tab = ft_strjoinplus(tab, line, 3);
	// }
	// ft_strdel(&line);
	// close(fd);
	// init_data_map(tab, data);
	// data->map = ft_calloc(data->map_h, sizeof(char*));
	// line_to_tab(tab, data);
}
