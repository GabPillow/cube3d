/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:33:55 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/20 15:35:44 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dest;

	if (!(dest = ft_strnew((ft_strlen(src)))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
