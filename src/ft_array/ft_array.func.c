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
# include <stdio.h>
#include <errno.h>
#include <ft_log.h>
#include <ft_printf.h>

static int check(t_array *array, int (*f)(void *, void *))
{
	if (!array)
	{
		return (
			ft_log$message(F, L,
						   "ft_array$cmp error: array ptr (null)",
						   EINVAL));
	}
	if (!f)
	{
		return (
			ft_log$message(F, L,
						   "ft_array$cmp error: func ptr (null)",
						   EINVAL));
	}
	return (0);
}

void *ft_array$func(
	t_array *array,
	int(*func)(void *, void *),
	void *param
)
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
			func(ft_array$at(array, array->i), param)
			)
			return (ft_array$at(array, array->i));
		array->i++;
	}
	if (
		func == ft_array$func_print_int || func == ft_array$func_print_str
		)
	{
		ft_printf("\n");
	}
	return (NULL);
}
