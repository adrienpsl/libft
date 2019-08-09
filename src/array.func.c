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

void *ft_array_el(t_array *array, int i)
{
	array->p.s = array->data + (i * array->element_size);
	return array->p.s;
}

void *ft_array_next_el(t_array *array)
{
	if (array->i >= array->length)
	{
		array->i = 0;
		return NULL;
	}
	else
	{
		array->p.s = array->data + (array->i * array->element_size);
		array->i++;
		return array->p.s;
	}
}

int ft_array_print_str(void *p1, void *p2, void *p3)
{
	(void)p2;
	(void)p3;
	(void)p1;
	ft_printf("-%s- ", p1);
	return (0);
}

void *ft_array_func(t_array *array,
					int(*f)(void *, void *, void *),
					void *param)
{
	size_t i;
	void *last;
	t_array *current;

	i = 0;
	if (!array)
		return NULL;
	while (i < array->length)
	{
		last = i > 0 ? ft_array_el(array, i - 1) : NULL;
		current = ft_array_el(array, i);
		if (f(current, last, param))
			return current;
		i++;
	}
	return (NULL);
}

int ft_array_cmp(t_array *array_1,
				 t_array *array_2,
				 int (*f)(void *, void *),
				 int mode)
{
	void *el_1;
	void *el_2;

	if (!array_1 ||  !array_2)
		return (1);
	array_1->i = 0;
	array_2->i = 0;
	while ((el_1 = ft_array_next_el(array_1))
		   && (el_2 = ft_array_next_el(array_2)))
	{
		if (mode == FT_CMP_STRING
			&& !ft_streq(el_1, el_2))
			return (1);
		else if (mode == FT_CMP_INT
				 && *(int*)el_1 != *(int*)el_2)
			return (1);
		else if (f && f(el_1, el_2))
			return (1);
	}
	el_2 = ft_array_next_el(array_2);
	if (el_1 != el_2)
		return (1);
	return (0);
}