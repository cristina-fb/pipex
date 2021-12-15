/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:44:30 by crisfern          #+#    #+#             */
/*   Updated: 2021/05/31 12:21:56 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	if (a == b)
		return (b);
	else if (a > b)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len > 0)
		{
			*(b + len - 1) = *(a + len - 1);
			len--;
		}
	}
	return (b);
}
