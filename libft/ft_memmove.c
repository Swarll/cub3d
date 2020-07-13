/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:56:27 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/17 17:15:43 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	const unsigned char	*src1;
	unsigned int		i;

	if (!dst && !src)
		return (0);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = -1;
	if (dst < src)
		while (++i < n)
			dst1[i] = src1[i];
	else
		while (n-- > 0)
			dst1[n] = src1[n];
	return (dst1);
}
