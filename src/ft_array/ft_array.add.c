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
//
//int ft_array_add(t_array **p_array, void *element)
//{
//	t_array *array;
//	if (!p_array || !*p_array || !element)
//		return (ft_errno_set(EINVAL, -1));
//	array = *p_array;
//	if (array->length + 1 >= array->capacity
//		&& !(array = ft_array_copy(array)))
//		return (-1);
//	if (!array->length)
//		ft_memcpy(ft_array_at(array, 0), element, array->element_size);
//	else
//		ft_memcpy(ft_array_at(array, array->length),
//				  element,
//				  array->element_size);
//	array->length += 1;
//	*p_array = array;
//	return (0);
//}


int ft_array_add(t_array **p_array, void *element)
{
	if (!p_array || !*p_array)
		return (ft_errno_set(EINVAL, -1));
	else
		return (ft_array_add_at(p_array, element, (*p_array)->length));
}

static int ft_array_move_end(t_array *array, int start)
{
	int index;

	if (array->length + 1 >= array->capacity)
		return (ft_errno_set(EFAULT, -1));
	index = array->length;
	while (index >= start)
	{
		ft_memcpy(ft_array_at(array, index + 1),
				  ft_array_at(array, index),
				  array->element_size);
		index = index - 1;
	}
	return (0);
}

int ft_array_add_at(t_array **p_array, void *element, int index)
{
	t_array *array;

	if (!p_array || !*p_array || !element)
		return (ft_errno_set(EINVAL, -1));
	array = *p_array;
	if (array->length + 1 >= array->capacity
		&& !(array = ft_array_copy(array)))
		return (-1);
	if (array->length && ft_array_move_end(array, index))
		return (-1);
	ft_memcpy(ft_array_at(array, index), element, array->element_size);
	array->length += 1;
	*p_array = array;
	return (0);
}
