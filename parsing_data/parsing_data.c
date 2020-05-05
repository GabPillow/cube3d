/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:41:40 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/05 19:24:37 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	char *check_line_tab(t_data *data, char *line)
{
	int i;

	i = 0;
	data->map_h += 1;
	while (line[i])
	{
		if (line[i] == '|')
		{
			ft_strdel(&line);
			ft_error(data, "Map is not correct");
		}
		i++;
	}
	line = ft_strjoinplus(line, "|", 1);
	return (line);
}

static void info_exist(t_data *data, char *line, int ret)
{
	if (data->wd_h == 0 || !data->list.north.id || !data->list.south.id \
	|| !data->list.west.id || !data->list.east.id || data->list.floor == -1 \
	|| data->list.ceiling == -1 || !line || !ret)
	{
		ft_strdel(&line);
		ft_error(data, "Missing params in configuration file");
	}
	// !&data->list.sprite
}

static int check_line(t_data *data, char *line)
{
	if (line[0] == 'R')
		init_resolution(data, line);
	else if (line[0] == 'N' && line[1] == 'O')
		init_texture(data, &data->list.north, line);
	else if (line[0] == 'S' && line[1] == 'O')
		init_texture(data, &data->list.south, line);
	else if (line[0] == 'W' && line[1] == 'E')
		init_texture(data, &data->list.west, line);
	else if (line[0] == 'E' && line[1] == 'A')
		init_texture(data, &data->list.east, line);
	else if (line[0] == 'F')
		data->list.floor = init_color(data, line);
	else if (line[0] == 'C')
		data->list.ceiling = init_color(data, line);
	else if (line && ft_strlen(line))
		return(1);
	return (0);
	// else if (line[0] == 'S' && line[1] == ' ')
	// 	init_texture(data->list.sprite, line);
}

void		parsing_data(char *path, t_data *data)
{
	int			fd;
	char		*line;
	char		*tab;
	int			ret;

	tab = NULL;
	line = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(data, "Configuration file does not exist");
	while ((ret = get_next_line(fd, &line)))
	{
		if (check_line(data, line))
			break;
		ft_strdel(&line);
	}
	info_exist(data, line, ret);
	tab = ft_strjoinplus(tab, check_line_tab(data, line), 3);
	while (get_next_line(fd, &line))
	{
		tab = ft_strjoinplus(tab, check_line_tab(data, line), 3);
		if (line)
			puts("a");
	}
	tab = ft_strjoinplus(tab, check_line_tab(data, line), 3);
	close(fd);
	line_to_tab(tab, data);
	int i;
	i = 0;
	while (i < data->map_h)
	{
		puts(data->map[i]);
		i++;
	}
	// init_data_map(data);
}
