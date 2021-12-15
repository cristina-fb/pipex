/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:00:29 by crisfern          #+#    #+#             */
/*   Updated: 2021/05/31 13:20:39 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	int		i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			if (!i++)
				aux = ft_lstnew((*f)(lst->content));
			else
				ft_lstadd_back(&aux, ft_lstnew((*f)(lst->content)));
			lst = lst->next;
		}
		if (0)
			(del)(lst->content);
		return (aux);
	}
	return (0);
}
