/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:14:13 by grigaux           #+#    #+#             */
/*   Updated: 2019/12/13 10:33:43 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buf(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*set_cache(char *buf, int start)
{
	int		i;
	char	*cache;

	if (!(cache = malloc(sizeof(buf) * (ft_strlen_gnl(&buf[start], 0) + 1))))
		return ((char *)NULL);
	i = 0;
	while (buf[start])
		cache[i++] = buf[start++];
	cache[i] = '\0';
	return (cache);
}

char	*write_line(char **line, char *buf)
{
	char	*tmp;

	if (!*line)
		return (ft_strdup_gnl(buf));
	else
	{
		tmp = *line;
		*line = ft_strjoin_gnl(*line, buf);
		free(tmp);
		return (*line);
	}
}

int		handle_cache(char **cache, char **line)
{
	char	*tmp;
	int		ret_val;

	ret_val = 0;
	if (*cache)
	{
		*line = write_line(line, *cache);
		if (check_buf(*cache) == -1)
		{
			free(*cache);
			*cache = 0;
		}
		else
		{
			ret_val = 1;
			tmp = *cache;
			if (!(*cache = set_cache(*cache, check_buf(*cache) + 1)))
				return (-1);
			free(tmp);
			tmp = 0;
		}
	}
	return (ret_val);
}

int		get_next_line(int fd, char **line)
{
	static char	*cache;
	char		buf[BUFFER_SIZE + 1];
	int			b_r;
	int			buf_size;
	int			ret_val;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	*line = NULL;
	if ((ret_val = handle_cache(&cache, line)) == 1 || ret_val == -1)
		return (ret_val);
	cache = 0;
	while (!cache && (b_r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b_r] = '\0';
		if ((buf_size = check_buf(buf)) != -1)
			cache = set_cache(buf, buf_size + 1);
		if ((buf_size != -1 && !cache) || (!(*line = write_line(line, buf))))
			return (-1);
	}
	if (!*line && (!(*line = ft_strdup_gnl(""))))
		return (-1);
	if (b_r == 0 && cache == 0)
		return (0);
	return (b_r == -1 ? -1 : 1);
}
