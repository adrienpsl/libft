/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int		ft_strclen(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		read_left(char **data, char **line, char c)
{
	char	*tmp;
	int		len;
	int		s_len;

	len = (int)ft_strlen(*data);
	if (c != 0)
	{
		s_len = ft_strclen(*data, c);
		if (!(*line = ft_strsub(*data, 0, s_len)))
			return (-1);
		tmp = *data;
		if (!(*data = ft_strsub(*data, s_len + 1, len - s_len - 1)))
			return (-1);
		free(tmp);
		return (1);
	}
	else
	{
		if (!(*line = ft_strsub(*data, 0, len)))
			return (-1);
		*data ? free(*data) : 0;
		if (!(*data = ft_strnew(0)))
			return (-1);
		return (1);
	}
}

int		read_line(char **data, char **line, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int 	ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = *data;
		if (!(*data = ft_strjoin(*data, buf, 0)))
			return (-1);
		free(tmp);
		if (ft_strclen(*data, '\n') != -1)
			return (read_left(data, line, '\n'));
	}
	if (ret == 0 && (int)ft_strlen(*data) > 0)
		return (read_left(data, line, 0));
	return (ret);
}

int		get_next_line(const int fd, char **line, int need_free)
{
	static char *data = NULL;

	if (fd < 0 || !line)
		return (-1);
	if (need_free)
	{
		free(data);
		return (0);
	}
	if (!data)
	{
		if (!(data = ft_strnew(0)))
			return (-1);
	}
	if (ft_strclen(data, '\n') != -1)
		return (read_left(&data, line, '\n'));
	return (read_line(&data, line, fd));
}