/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnplus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:01:15 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/05 19:12:19 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinnplus(char *s1, char *s2, int c, size_t len2)
{
	char *str_new;

	str_new = NULL;
	if (s1 && !s2)
	{
		if (!(str_new = ft_strdup(s1)))
			return (NULL);
	}
	else if (s2 && !s1)
	{
		if (!(str_new = ft_strndup(s2, len2)))
			return (NULL);
	}
	else if (s1 && s2)
	{
		if (!(str_new = ft_strnew(ft_strlen(s1) + len2)))
			return (NULL);
		ft_strcpy(str_new, s1);
		ft_strncat(str_new, s2, len2);
	}
	if (s1 && (c == 1 || c == 3))
		ft_strdel(&s1);
	if (s2 && (c == 2 || c == 3))
		ft_strdel(&s2);
	return (str_new);
}
