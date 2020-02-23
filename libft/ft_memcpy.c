/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:58:41 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/22 17:58:41 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*svg;

	if (!dest && !src)
		return (NULL);
	svg = dest;
	while (n--)
		(*(char*)dest++) = (*(char*)src++);
	return (svg);
}
