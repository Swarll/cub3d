/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:43:23 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/10 15:51:36 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;
	char	*str;

	str = (char *)s;
	i = 0;
	pos = 0;
	while (str[i])
	{
		if (str[i] == c)
			pos = i;
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	else if (c == str[pos])
		return (&str[pos]);
	else
		return (0);
}
