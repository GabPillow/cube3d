/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:41:40 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/21 12:11:20 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		line_to_tab(char *line, t_map *map)
{
	int	i;
	int	b;

	b = 0;
	i = 0;
	while (i < map->size_h)
	{
		map->map[i] = line + b;
		b += map->size_w;
		i++;
	}
}

void		get_map(char *path, t_map *map)
{
	int			fd;
	char		*line;
	char		*tab;

	map->map = NULL;
	tab = NULL;
	fd = open(path, O_RDONLY);
	map->size_h = get_next_line(fd, &line);
	map->size_w = (int)ft_strlen(line);
	tab = ft_strjoinplus(tab, line, 3);
	while (get_next_line(fd, &line))
	{
		map->size_h++;
		tab = ft_strjoinplus(tab, line, 3);
	}
	map->map = ft_calloc(map->size_h, sizeof(char*));
	line_to_tab(tab, map);
}
