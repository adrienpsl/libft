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

#include "libft.h"

t_buffer *ft_buffer_new(size_t size, int fd)
{
	t_buffer *buffer;

	if (!(buffer = ft_array_new(size, 1)))
		return (NULL);
	buffer->param = fd;
	return (buffer);
}

int ft_buffer_clean(t_buffer *buff)
{
	write(buff->param, buff->data, buff->i);
	ft_memset(buff->data, 0, buff->i);
	buff->i = 0;
	return (0);
}

int ft_buffer_add(t_buffer *buff, char *data, size_t size)
{
	if (size == STRING_MODE)
		size = ft_strlen(data);
	if (!size)
		return (0);
	if ((size - 1) > buff->length)
	{
		ft_putstr_fd("buffer to small to handel data", 2);
		ft_buffer_clean(buff);
		ft_putstr_fd(data, 1);
		return (0);
	}
	if (size + buff->i > buff->length)
		ft_buffer_clean(buff);
	ft_memcpy(buff->data + buff->i, data, size);
	buff->i += size;
	return (0);
}
