/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:45:16 by crisfern          #+#    #+#             */
/*   Updated: 2021/06/03 09:29:36 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	get_digits(int n)
{
	int				digits;
	unsigned int	num;

	digits = 1;
	if (n < 0)
	{
		digits++;
		num = n * (-1);
	}
	else
		num = n;
	while (num > 9)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	unsigned int	dig;
	char			*str;

	dig = get_digits(n) + 1;
	str = ft_calloc(dig, 1);
	num = (unsigned int) n;
	if (n < 0)
		num *= -1;
	if (str)
	{
		str[dig - 1] = '\0';
		while (--dig > 0)
		{
			if ((n < 0) && (dig == 1))
				str[0] = '-';
			else
			{
				str[dig - 1] = '0' + num % 10;
				num /= 10;
			}
		}
	}
	return (str);
}
