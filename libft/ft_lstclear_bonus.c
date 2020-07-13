/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:06:34 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/22 16:27:00 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*act;
	t_list	*next;

	if (lst && *lst && del)
	{
		act = *lst;
		while (act)
		{
			next = act->next;
			ft_lstdelone(act, (*del));
			act = next;
		}
		*lst = 0;
	}
}
