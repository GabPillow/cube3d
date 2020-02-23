
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:28:42 by grochefo          #+#    #+#             */
/*   Updated: 2019/01/31 12:58:46 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (ft_strlen(src) < n)
		n = ft_strlen(src);
	i = ft_strlen(dest);
	ft_strncpy(dest + i, src, n);
	dest[i + n] = '\0';
	return (dest);
}
