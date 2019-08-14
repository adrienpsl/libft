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

#include <ft_log.h>
#include "ft_mem.h"
#include "ft_errno.h"
#include "ft_array.h"

int static check(t_array *array, int index)
{
	if (NULL == array)
	{
		return (
			ft_log$message(F, L,
						   "ft_array$remove error: array ptr (null)",
						   EINVAL)
		);
	}
	else if (index >= array->length || index < 0)
	{
		return (ft_log$message(F, L, "ft_array$remove"
									 " index bigger than length/neg", EINVAL));
	}
	else if (!array->length)
	{
		return (ft_log$message(F, L, "ft_array$insert"
									 " array is empty", EINVAL));
	}
	else
	{
		return (0);
	}
}

int ft_array$remove(t_array *array, int index)
{
	if (
		0 != check(array, index)
		)
		return (-1);
	{
		ft_memmove(ft_array$at(array, index),
				   ft_array$at(array, index + 1),
				   (array->length - index) * array->element_size);
	}
	{
		array->length -= 1;
		return (0);
	}
}
