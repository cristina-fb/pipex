/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:57:57 by crisfern          #+#    #+#             */
/*   Updated: 2021/06/03 09:31:19 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*nxt;

	aux = *lst;
	while (aux)
	{
		nxt = aux->next;
		ft_lstdelone(aux, (*del));
		aux = nxt;
	}
	free(aux);
	*lst = 0;
}
