/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:01:34 by crisfern          #+#    #+#             */
/*   Updated: 2021/05/31 12:31:32 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_max;

	i = 0;
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
	{
		len_max = ft_strlen(src) + ft_strlen(dst);
		while (*(dst + i))
			i++;
		while (*src && (i < (dstsize - 1)))
			*(dst + i++) = *src++;
		*(dst + i) = '\0';
		return (len_max);
	}
	return (0);
}
