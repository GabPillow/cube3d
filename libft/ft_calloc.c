/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:11:11 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/22 17:29:32 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*zm;

	if (!(zm = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(zm, size * nmemb);
	return (zm);
}
