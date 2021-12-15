/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:35:09 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/23 15:54:49 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned int	num;

	i = 0;
	neg = 0;
	num = 0;
	while ((str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
		num = (num * 10) + str[i++] - 48;
	if ((num > 2147483647) && (!neg))
		return (-1);
	else if ((num > 2147483648) && (neg))
		return (0);
	else if (neg)
		num = ((int) num) * -1;
	return (num);
}
