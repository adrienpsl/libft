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

#include <ft_array.h>
#include <ft_mem.h>
#include <ft_log.h>
#include <errno.h>

int static check(t_array **p_array, void *element, int index)
{
	if (!p_array || !*p_array || !element)
	{
		return (ft_log$null(__FILE__, __LINE__));
	}
	else if (index > (*p_array)->length)
	{
		return (ft_log$message(F, L, "index bigger than length", EINVAL));
	}
	else if (index < 0)
	{
		return (ft_log$message(F, L, "negative index", EINVAL));;
	}
	else
	{
		return (0);
	}
}

static t_array *handle_grow(t_array *array)
{
	if (array->length + 1 >= array->capacity)
	{
		if (!(array = ft_array$double_size(array)))
			return (NULL);
	}
	return (array);
}

static void move_and_copy_value(t_array *array, void *element, int index)
{
	if (
		index < array->length
		)
	{
		ft_memmove(ft_array$at(array, index + 1),
				   ft_array$at(array, index),
				   (array->length - array->i) * array->element_size);
	}
	{
		ft_memcpy(ft_array$at(array, index), element, array->element_size);
		array->length += 1;
	}
}

int ft_array$push_at(t_array **p_array, void *element, int index)
{
	t_array *array;

	if (
		check(p_array, element, index)
		)
		return (-1);
	if (
		!(array = handle_grow(*p_array))
		)
		return (-1);
	{
		move_and_copy_value(array, element, index);
	}
	*p_array = array;
	return (0);
}