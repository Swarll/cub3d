/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:50:47 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/23 15:05:01 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*list;
	t_list	*new;
	t_list	*begin;

	list = 0;
	if (lst && f)
	{
		begin = ft_lstnew(f(lst->content));
		list = begin;
		lst = lst->next;
		while (lst)
		{
			new = ft_lstnew(f(lst->content));
			list->next = new;
			list = new;
			lst = lst->next;
		}
		return (begin);
	}
	else
		return (0);
}
