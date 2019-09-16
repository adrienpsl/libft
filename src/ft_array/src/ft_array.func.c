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

static int check(t_array *array, int (*f)(void *, void *))
{
	if (!array)
	{
		return (
			ftlog__message(F, L,
				"ftarray__func error: array ptr (null)",
				EINVAL));
	}
	if (!f)
	{
		return (
			ftlog__message(F, L,
				"ftarray__func error: func ptr (null)",
				EINVAL));
	}
	return (0);
}

void	*ftarray__func(t_array *array, int(*func)(void *, void *), void *param)
{
	if (
		check(array, func)
		)
		return (NULL);
	array->i = 0;
	while (
		array->i < array->length
		)
	{
		if (
			func(ftarray__at(array, array->i), param)
			)
			return (ftarray__at(array, array->i));
		array->i++;
	}
	if (
		func == ftarray__func_print_int || func == ftarray__func_print_str
		)
	{
		ft_printf("\n");
	}
	return (NULL);
}
