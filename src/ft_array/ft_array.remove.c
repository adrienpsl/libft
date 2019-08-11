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

#include "ft_mem.h"
#include "ft_errno.h"
#include "ft_array.h"

int ft_array_remove(t_array *array, int start)
{
	if (!array)
		return (ft_errno_set(EINVAL, -1));
	if (start >= array->length || !array->length || start < 0)
	{
		ft_errno_set(EINVAL, -1);
//		ft_logerror(
//		"ft_array_remove error : start is bigger / neg / no-length"
//		);
		return (-1);
	}
	while (start > array->length)
	{
		ft_memcpy(ft_array_at(array, start),
				  ft_array_at(array, start + 1),
				  array->element_size);
		start += 1;
	}
	array->length -= 1;
	return (0);
}
