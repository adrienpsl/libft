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

#include "ft_str.h"
#include "ft_mem.h"
#include "ft_buffer.h"

int ft_buffer_clean(t_buffer *buff)
{
	ft_putstr_fd(buff->data, buff->fd);
	ft_bzero(buff->data, buff->length);
	buff->length = 0;
	return (0);
}

int ft_buffer_add(t_buffer *buff, char *data, int size)
{
	if (size > BUFFER_SIZE)
	{
		ft_putstr_fd("buffer to small to handel data", 2);
		ft_buffer_clean(buff);
		ft_putstr_fd(data, buff->fd);
		return (-1);
	}
	if (size + buff->length >= BUFFER_SIZE)
	{
		ft_buffer_clean(buff);
	}
	ft_memcpy(buff->data + buff->length, data, size);
	buff->length += size;
	return (0);
}
