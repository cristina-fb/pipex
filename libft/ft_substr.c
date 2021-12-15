/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:25:50 by crisfern          #+#    #+#             */
/*   Updated: 2021/05/31 09:24:37 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s)
	{
		if (start < ft_strlen(s))
		{
			i = 0;
			if (len > ft_strlen(s) - start)
				len = ft_strlen(s) - start;
			ptr = ft_calloc(len + 1, 1);
			if (ptr)
			{
				while ((len-- > 0) && (s + start + i++))
					*(ptr + i - 1) = *(s + start + i - 1);
				*(ptr + i) = 0;
				return (ptr);
			}
		}
		else
			return (ft_strdup(""));
	}
	return (0);
}
