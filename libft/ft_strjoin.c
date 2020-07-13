/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:03:29 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/23 15:24:36 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*res_cpy;

	if (!s1 || !s2)
		return (0);
	if (!(res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (0);
	res_cpy = res;
	while (*s1 != '\0')
		*res_cpy++ = *s1++;
	while (*s2 != '\0')
		*res_cpy++ = *s2++;
	*res_cpy = '\0';
	return (res);
}
