/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:55:09 by crisfern          #+#    #+#             */
/*   Updated: 2021/06/03 09:37:45 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	char			*aux;
	unsigned int	i;

	if (f && s)
	{
		i = 0;
		str = ft_calloc(ft_strlen(s) + 1, 1);
		if (str)
		{
			aux = str;
			while (*s)
				*aux++ = (*f)(i++, *s++);
			*aux = '\0';
			return (str);
		}
	}
	return (0);
}
