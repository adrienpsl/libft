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
			ftlog__message(F, L,
				"ftarray__remove error: array ptr (null)",
				EINVAL)
		);
	}
	else if (index >= array->length || index < 0)
	{
		return (ftlog__message(F, L, "ftarray__remove"
									 " index bigger than length/neg", EINVAL));
	}
	else if (!array->length)
	{
		return (ftlog__message(F, L, "ftarray__remove"
									 " array is empty", EINVAL));
	}
	else
	{
		return (0);
	}
}

int ftarray__remove(t_array *array, int index)
{
	if (
		0 != check(array, index)
		)
		return (-1);
	{
		ft_memmove(ftarray__at(array, index),
			ftarray__at(array, index + 1),
			(array->length - index) * array->element_size);
	}
	{
		array->length -= 1;
		return (0);
	}
}
