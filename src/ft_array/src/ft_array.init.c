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

static int				check(int nb_elements, size_t element_size)
{
	if (nb_elements < 0)
	{
		return (ftlog__message(F, L, "ft_array$init : no elements number",
				EINVAL));
	}
	if (0 == element_size)
	{
		return (ftlog__message(F, L, "ft_array$init : element size (null)",
				EINVAL));
	}
	else
		return (0);
}

static int				allocation(
	t_array **p_array,
	int nb_elements,
	int element_size)
{
	t_array	*array;
	void	*data;
	void	*buffer;

	if (NULL == (array = ft_memalloc(sizeof(t_array)))
		|| NULL == (data = ft_memalloc((nb_elements + 1) * element_size))
		|| NULL == (buffer = ft_memalloc(element_size * 2)))
		return (-1);
	else
	{
		array->data = data;
		array->buffer = buffer;
		*p_array = array;
		return (0);
	}
}

t_array					*ftarray__init(int nb_elements, size_t element_size)
{
	t_array *array;

	if (check(nb_elements, element_size))
		return (NULL);
	nb_elements = nb_elements * 2;
	if (OK == allocation(&array, nb_elements, element_size))
	{
		array->element_size = element_size;
		array->capacity = nb_elements;
		return (array);
	}
	else
		return (NULL);
}

t_array					*ftarray__init_data(
	void *start,
	int nb_element,
	size_t element_size)
{
	t_array *array;

	if (check(nb_element, element_size))
	{
		return (NULL);
	}
	if (!start)
	{
		ftlog__message(F, L, "ft_array$init_data : start (null)",
			EINVAL);
		return (NULL);
	}
	if (NULL == (array = ftarray__init(nb_element, element_size)))
	{
		return (NULL);
	}
	{
		ft_memcpy(array->data, start, nb_element * element_size);
		array->length = nb_element;
		return (array);
	}
}
