/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:02:07 by grigaux           #+#    #+#             */
/*   Updated: 2020/07/01 11:21:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		tab[i] = 0;
		i--;
	}
	free(tab);
	return (0);
}

static int	count_of_sep(char *str, char c)
{
	int i;
	int res;

	i = 1;
	res = 0;
	while (str[i])
	{
		if ((str[i] == c) && !(str[i - 1] == c))
			res++;
		i++;
	}
	return (res);
}

static char	*ft_strndupp(int k, int i, char *src, char **res)
{
	char	*dest;
	int		j;

	j = 0;
	if (!(dest = malloc(sizeof(src) * (i - k) + 1)))
		return (0);
	else
		(void)res;
	while (k <= i)
	{
		dest[j] = src[k];
		k++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static char	**fill_tab(char const *s, char **r, char c, int i)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (s[++i])
	{
		if (s[k] == c)
			k = i + 1;
		else if (s[i] == c || s[i + 1] == '\0')
		{
			if (s[i + 1] == '\0' && (!(s[i] == c)))
				r[l++] = ft_strndupp(k, i, (char *)s, r);
			else
				r[l++] = ft_strndupp(k, i - 1, (char *)s, r);
			k = i + 1;
			if (!r[l - 1])
				return (ft_free(r, l - 2));
		}
	}
	r[l] = 0;
	return (r);
}

char		**ft_split(char const *s, char c)
{
	char	**r;

	if (!(s) || !(r = malloc(sizeof(char**) * (count_of_sep((char *)s, c)
						+ 2))))
		return (0);
	return (fill_tab(s, r, c, -1));
}
