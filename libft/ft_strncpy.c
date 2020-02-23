
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:05:54 by grochefo          #+#    #+#             */
/*   Updated: 2018/11/22 18:19:35 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	ft_memcpy(dest, src, n);
	while (ft_strlen(src) + i < n)
	{
		dest[ft_strlen(src) + i] = '\0';
		i++;
	}
	return (dest);
}