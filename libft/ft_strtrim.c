/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:16:38 by grigaux           #+#    #+#             */
/*   Updated: 2019/10/23 14:07:52 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *set)
{
	int i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static int	seek_start(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (is_charset(s1[i], set))
		i++;
	return (i);
}

static int	seek_end(char const *s1, char const *set)
{
	int i;

	i = ft_strlen(s1) - 1;
	while (is_charset(s1[i], set))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*res;
	int		size;

	if (!s1)
		return (0);
	start = seek_start(s1, set);
	end = seek_end(s1, set);
	if (end - start < 0)
		size = 0;
	else
		size = end - start + 1;
	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
