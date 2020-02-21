/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:52:00 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/20 17:25:46 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncpy(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (src && src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_strjoinspe(char *s1, char *s2)
{
	char	*str_new;

	if (!(str_new = (char*)ft_calloc(ft_strlenn(s1, '\0') +
	ft_strlenn(s2, '\n') + 1, sizeof(char))))
		return (NULL);
	ft_strncpy(str_new, s1, '\0');
	ft_strncpy(str_new + ft_strlenn(str_new, '\0'), s2, '\n');
	if (s1)
		free(s1);
	s1 = NULL;
	return (str_new);
}

size_t	ft_strlenn(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}
