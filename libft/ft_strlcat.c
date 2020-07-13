/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:14:20 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/15 10:24:54 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int j;
	unsigned int total;

	i = 0;
	j = 0;
	total = 0;
	while (dest[i] && i < n)
		i++;
	total += i;
	while (src[j])
		j++;
	total += j;
	if (i == n)
		return (total);
	j = 0;
	while (src[j] && i + j < n - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (total);
}
