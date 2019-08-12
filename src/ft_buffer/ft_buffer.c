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

#include "libft_define.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "ft_buffer.h"

int ft_buffer_clean(t_buffer *buff)
{
	ft_putstr_fd(buff->data, 1);
	ft_memset(buff->data, 0, buff->i);
	buff->i = 0;
	return (0);
}

int ft_buffer_add(t_buffer *buff, char *data, int size)
{
	if (!size)
		return (0);
	if ((size - 1) > buff->length)
	{
//		ft_putstr_fd("buffer to small to handel data", 2);
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
