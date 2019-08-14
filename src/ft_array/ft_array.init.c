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
#include <errno.h>
#include <ft_log.h>
#include "ft_array.h"

static int check(int nb_elements, size_t element_size)
{
	if (nb_elements < 1)
	{
		return (
			ft_log$message(F, L, "ft_array$init : no elements number",
						   EINVAL)
		);
	}
	if (!element_size)
	{
		return (
			ft_log$message(F, L, "ft_array$init : element size (null)",
						   EINVAL)
		);
	}
	else
	{
		return (0);
	}
}

/*
** I add three to protect overflow and add buffer into then like :
** { [end array] [protect] [buffer] [protect] }
*/
t_array *ft_array$init(int nb_elements, size_t element_size)
{
	t_array *array;

	if (
		check(nb_elements, element_size)
		)
		return (NULL);
	nb_elements = nb_elements * 2;
	array = ft_memalloc(
		sizeof(t_array) + (nb_elements * (element_size + 3))
	);
	if (array)
	{
		array->data = ((char *)array) + sizeof(t_array);
		array->element_size = element_size;
		array->capacity = nb_elements;
		array->buffer =
			array->data + ((array->capacity + 1) * element_size);
		return (array);
	}
	else
		return (NULL);
}

t_array *ft_array$init_data(void *start, int nb_element, size_t element_size)
{
	t_array *array;

	if (check(nb_element, element_size))
	{
		return (NULL);
	}
	if (!start)
	{
		ft_log$message(F, L, "ft_array$init_data : start (null)",
					   EINVAL);
		return (NULL);
	}
	if (
		!(array = ft_array$init(nb_element, element_size))
		)
	{
		return (NULL);
	}
	{
		ft_memcpy(array->data, start, nb_element * element_size);
		array->length = nb_element;
		return (array);
	}
}