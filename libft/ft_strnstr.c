/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:48:02 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/19 11:47:48 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = 0;
	while (str[i])
	{
		a = i;
		j = 0;
		if (str[i] == to_find[0])
			while (str[a] == to_find[j] && a < n)
			{
				if (j == ft_strlen(to_find) - 1)
					return ((char *)&str[i]);
				a++;
				j++;
			}
		i++;
	}
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	else
		return (0);
}
