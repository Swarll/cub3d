/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:14:25 by grigaux           #+#    #+#             */
/*   Updated: 2019/12/10 14:24:36 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s1)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = malloc((sizeof(char) * (ft_strlen_gnl(s1, 1) + 1)))))
		return (NULL);
	while (s1 && s1[i] && s1[i] != '\n')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		ft_strlen_gnl(const char *str, int n)
{
	int i;

	i = 0;
	if (n == 0)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		while (str[i] && str[i] != '\n')
			i++;
		return (i);
	}
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	char	*res_cpy;

	if (!(res = malloc((ft_strlen_gnl(s1, 1) + ft_strlen_gnl(s2, 1) + 1)
				* sizeof(char))))
		return (0);
	res_cpy = res;
	while (*s1 != '\0' && *s1 != '\n')
		*res_cpy++ = *s1++;
	while (*s2 != '\0' && *s2 != '\n')
		*res_cpy++ = *s2++;
	*res_cpy = '\0';
	return (res);
}
