/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:18:48 by grigaux           #+#    #+#             */
/*   Updated: 2020/02/28 10:32:48 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(long long n, int size)
{
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

static void	itoa_rec(char *res, long long n, int i)
{
	if (n > 9)
	{
		itoa_rec(res, n / 10, --i);
		res[i] = (n % 10) + 48;
	}
	else
		res[--i] = n + 48;
}

char		*ft_itoa(int n)
{
	int			neg;
	char		*res;
	int			size;
	int			i;
	long long	a;

	a = n;
	i = 0;
	neg = 1;
	size = 0;
	if (a < 0)
	{
		size++;
		a *= -1;
		neg *= -1;
	}
	size = int_size(a, size);
	if (!(res = malloc(size * sizeof(char) + 1)))
		return (0);
	if (neg < 1)
		res[i++] = '-';
	itoa_rec(res, a, size);
	res[size] = '\0';
	return (res);
}
