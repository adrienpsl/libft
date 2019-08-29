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

#include <ft_array.h>
#include <ft_log.h>
#include <ft_mem.h>

int static check(t_array *array, int index, void (*f)(void *, void *))
{
	if (
		NULL == array
		)
		return (
			ftlog__message(F, L,
						   "ftarray__remove_func error: array ptr (null)",
						   EINVAL)
		);
	else if (
		index >= array->length || index < 0
		)
		return (ftlog__message(F, L, "ftarray__remove_func"
									 " index bigger than length/neg", EINVAL));
	else if (
		!array->length
		)
		return (ftlog__message(F, L, "ftarray__remove_func"
									 " array is empty", EINVAL));
	if (
		NULL == f
		)
		return (ftlog__message(F, L, "ftarray__remove_func"
									 " func is nulll", EINVAL));
	else
		return (0);
}

int
ftarray__remove_func(t_array *array, int index, void (*f)(void *, void *),
	void *param)
{
	if (
		0 != check(array, index, f)
		)
		return (-1);
	{
		f(ftarray__at(array, index), param);
		ft_memmove(ftarray__at(array, index),
				   ftarray__at(array, index + 1),
				   (array->length - index) * array->element_size);
	}
	{
		array->length -= 1;
		return (0);
	}
}