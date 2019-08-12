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

#include <ft_errno.h>
#include <ft_mem.h>
#include <ft_log.h>
#include "ft_array.h"

int ft_array_add(t_array **p_array, void *element)
{
	(void) "____check";
	{
		if (!p_array || !*p_array || !element)
			return (ft_log_null(__FILE__, __LINE__));
		else
			return (ft_array_add_at(p_array, element, (*p_array)->length));
	}
}

int ft_array_add_at(t_array **p_array, void *element, int index)
{
	t_array *array;

	(void) "____ check";
	{
		if (!p_array || !(array = *p_array) || !element)
			return (ft_log_null(__FILE__, __LINE__));
		if (index >= array->capacity)
			return (ft_log_message(F, L, "index bigger capacity", EINVAL));
	}
	(void) "____ create a new tab 2 times bigger";
	{
		if (array->length + 1 >= array->capacity
			&& !(array = ft_array$double_size(array)))
			return (-1);
	}
	(void) "____ make place and copy the value";
	{
		(index < array->length) && ft_memmove(ft_array_at(array, index + 1),
											  ft_array_at(array, index),
											  (array->length - array->i) *
											  array->element_size);
		ft_memcpy(ft_array_at(array, index), element, array->element_size);
		array->length += 1;
		*p_array = array;
	}
	return (0);
}
