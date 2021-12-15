/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:40:51 by crisfern          #+#    #+#             */
/*   Updated: 2021/05/31 12:30:09 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len;

	len = 0;
	if (!src)
		return (0);
	else if (*src)
	{
		while (*src)
		{
			len++;
			if (dstsize > 1)
			{
				dstsize--;
				*dst++ = *src;
			}
			src++;
		}
		if (dstsize > 0)
			*dst = 0;
		return (len);
	}
	*dst = 0;
	return (0);
}
