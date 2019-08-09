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

int ft_array_add(t_array **p_array, void *element)
{
	t_array *new_array;
	t_array *array;
	char *position;

	if (!p_array || !*p_array || !element)
		return (ft_errno_set(EINVAL, -1));
	array = *p_array;
	if (array->length + 1 == array->capacity)
	{
		if (!(new_array = ft_array_init(array->capacity,
										array->element_size))
			|| ft_array_copy(new_array, array)
		)
			return (-1);
	}
	position = ft_array_position(array, array->length);
	ft_memcpy(position, element, array->element_size);
	*p_array = array;
	return (0);
}
