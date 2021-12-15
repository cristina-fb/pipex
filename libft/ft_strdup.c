/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:51:52 by crisfern          #+#    #+#             */
/*   Updated: 2021/05/31 13:01:53 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = ft_calloc(len + 1, 1);
	if (ptr)
	{
		while (len-- > 0)
		{
			*(ptr + i) = *(s1 + i);
			i++;
		}
		*(ptr + i) = 0;
		return (ptr);
	}
	return (0);
}
