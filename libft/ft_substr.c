/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:25:31 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/23 13:57:13 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	char			*to_copy;
	char			*res_copy;

	if (!(s) || !(res = malloc((len + 1) * sizeof(char))))
		return (0);
	if (start > ft_strlen(s))
		res[0] = '\0';
	else
	{
		to_copy = (char *)s + start;
		res_copy = res;
		while (*to_copy && len-- > 0)
			*res_copy++ = *to_copy++;
		*res_copy = '\0';
	}
	return (res);
}
