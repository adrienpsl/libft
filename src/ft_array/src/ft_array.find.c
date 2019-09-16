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

#include "ft_array.h"
#include <errno.h>
#include <ft_log.h>
#include <ft_printf.h>

static int			check(
	t_array *array,
	int (*f)(void *, void *))
{
	if (NULL == array)
		return (
			ftlog__message(F, L,
				"ftarray__find error: array ptr (null)",
				EINVAL));
	if (NULL == f)
		return (
			ftlog__message(F, L,
				"ftarray__find error: func ptr (null)",
				EINVAL));
	return (0);
}

int					ftarray__find(
	t_array *array,
	int (*func)(void *, void *),
	void *param)
{
	if (check(array, func))
		return (-1);
	array->i = 0;
	while (array->i < array->length)
	{
		if (func(ftarray__at(array, array->i), param))
			return (array->i);
		array->i++;
	}
	return (-1);
}
