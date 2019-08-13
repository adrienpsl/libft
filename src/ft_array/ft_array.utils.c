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

#include "ft_errno.h"
#include "ft_mem.h"
#include "ft_array.h"

void ft_array_clear(t_array *array)
{
	if (!array)
	{
		ft_errno_set(EFAULT, -1);
		return;
	}
	ft_bzero(array->data, array->length * array->element_size);
	array->length = 0;
}

void *ft_array_position(t_array *array, int index)
{
	if (!array)
	{
		ft_errno_set(EFAULT, -1);
		return (NULL);
	}
	return (array->data + (index * array->element_size));
}
