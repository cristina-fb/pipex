/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:00:21 by crisfern          #+#    #+#             */
/*   Updated: 2021/05/31 16:21:26 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	max;

	max = len - ft_strlen(needle);
	if (max < 0)
		max = ft_strlen(haystack);
	if (!*needle)
		return ((char *)haystack);
	else if (len)
	{
		while (*haystack && (max-- >= 0))
			if (!ft_strncmp(haystack++, needle, ft_strlen(needle)))
				return ((char *)(haystack - 1));
	}
	return (0);
}
