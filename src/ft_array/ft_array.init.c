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

#include <ft_mem.h>
#include "ft_array.h"

/*
** I add three to protect overflow and add buffer into then like :
** { [end array] [protect] [buffer] [protect] }
*/
t_array *ft_array_init(int nb_elements, size_t element_size)
{
	t_array *array;

	nb_elements = nb_elements * 2;
	array = ft_memalloc(
		sizeof(t_array) + (nb_elements * (element_size + 3))
	);
	if (array)
	{
		array->data = ((char *) array) + sizeof(t_array);
		array->element_size = element_size;
		array->capacity = nb_elements;
		array->buffer =
			array->data + ((array->capacity + 1) * element_size);
		return (array);
	}
	else
		return (NULL);
}