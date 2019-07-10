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

t_array *ft_array_new(int length, int size_el)
{
	t_array *array;

	if (!(array = ft_memalloc(sizeof(t_array) + (length * size_el))))
		return (NULL);
	array->size_el = size_el;
	array->data = (char *) array + (sizeof(size_t) * 4) + sizeof(char *) + PTR_SIZE;
	array->p.s = array->data;
	array->length = length;
	return (array);
}

void ft_array_free(t_array **p_array)
{
	t_array *arr;

	if (!p_array || !*p_array)
		return;
	arr = *p_array;
	ft_memdel((void **) &arr, sizeof(t_array) + (arr->length * arr->size_el));
	*p_array = NULL;
}

void ft_array_clean(t_array *array)
{
	ft_memset(array->data, 0, array->length * array->size_el);
	array->i = 0;
}

t_array *ft_array_dup(t_array *origin, size_t size)
{
	t_array *array;

	if (!(array = ft_array_new(
					 size == SAME_SIZE ? origin->length : size,
					 origin->size_el)))
		return (NULL);
	ft_memcpy(array->data,
				origin->data,
				origin->length * origin->size_el);
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