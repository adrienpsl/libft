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
#include "ft_array.h"

void *ft_array$prev_loop(t_array *array)
{
	void *element;

	if (!array)
	{
		ft_log$message(F, L,
					   "ft_array$prev_loop error: array ptr (null)",
					   EINVAL);
		return (NULL);
	}
	element = ft_array_position(array, array->i);
	{
		array->i =
			(array->i - 1 < 0) ?
			array->length - 1 : array->i - 1;
	}
	return (element);
}

void *ft_array$prev(t_array *array)
{
	void *element;
	static int end = 0;

	if (!array)
	{
		ft_log$message(F, L,
					   "ft_array$prev error: array ptr (null)",
					   EINVAL);
		return (NULL);
	}
	if (array->i == 0 && end)
		return (NULL);
	else if (array->i != 0)
		end = 0;
	else if (array->i == 0 && !end)
		end = 1;
	element = ft_array_position(array, array->i);
	array->i != 0 && (array->i -= 1);
	return (element);
}