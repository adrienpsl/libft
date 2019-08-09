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

// TODO : mettre size t
t_array *ft_array_new(int length, int size_el)
{
	t_array *array;

	array = ft_memalloc(sizeof(t_array) + (length * size_el));
	if (array)
	{
		array->element_size = size_el;
		array->data = (char*)array + sizeof(t_array);
		array->length = length;
	}
	return (array);
}

void ft_array_free(t_array **p_array)
{
	if (!p_array || !*p_array)
		return;
	ft_array_clean(*p_array);
	ft_bzero(*p_array, sizeof(t_array));
	*p_array = NULL;
}

void ft_array_clean(t_array *array)
{
	ft_memset(array->data, 0, array->length * array->element_size);
	array->i = 0;
}

t_array *ft_array_dup(t_array *origin, size_t size)
{
	t_array *array;

	if (!(array = ft_array_new(
	 size == SAME_SIZE ? origin->length : size,
	 origin->element_size)))
		return (NULL);
	ft_memcpy(array->data,
			  origin->data,
			  origin->length * origin->element_size);
	return (array);
}

t_array *ft_array_dup_bigger(t_array **p_origin, size_t add_size)
{
	t_array *new;
	t_array *origin;

	origin = *p_origin;
	if (!(new = ft_array_dup(origin, origin->length + add_size)))
		return (NULL);
	ft_array_free(p_origin);
	return (new);
}