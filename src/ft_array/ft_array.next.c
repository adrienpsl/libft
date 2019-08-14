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

#include <errno.h>
#include <ft_log.h>
#include "ft_array.h"

void *ft_array$next_loop(t_array *array)
{
	void *element;

	if (!array)
	{
		ft_log$message(F, L,
					   "ft_array$next_loop error: array ptr (null)",
					   EINVAL);
		return (NULL);
	}
	element = ft_array_position(array, array->i);
	{
		array->i =
			(array->i + 1 == array->length) ?
			0 : array->i + 1;
	}
	return (element);
}

void *ft_array$next(t_array *array)
{
	void *element;

	if (!array)
	{
		ft_log$message(F, L,
					   "ft_array$next error: array ptr (null)",
					   EINVAL);
		return (NULL);
	}
	else if (array->i == array->length)
	{
		return (NULL);
	}
	else
	{
		element = ft_array_position(array, array->i);
		array->i += 1;
		return (element);
	}
}
