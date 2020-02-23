/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:57:23 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/23 12:54:42 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_manage_buff(char *buff)
{
	int		i;
	int		b;
	int		ret;

	ret = 0;
	b = 0;
	i = 0;
	while (buff[i] && buff[i] != '\n')
		buff[i++] = 0;
	if (buff[i] == '\n')
	{
		ret = 1;
		buff[i] = 0;
		i++;
	}
	while (i < BUFFER_SIZE + 1)
	{
		buff[b] = buff[i];
		buff[i] = 0;
		b++;
		i++;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];

	if (!line || BUFFER_SIZE < 0 || read(fd, buff, 0) == -1 ||
	(!(*line = (char*)ft_calloc(1, sizeof(char)))))
		return (-1);
	while (buff[0] || read(fd, buff, BUFFER_SIZE))
	{
		*line = ft_strjoinnplus(*line, buff, 1, ft_strlenn(buff, '\n'));
		if (ft_manage_buff(buff))
			return (1);
	}
	return (0);
}
