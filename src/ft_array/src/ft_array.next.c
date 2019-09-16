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

void	*ftarray__next_loop(t_array *array)
{
	void *element;

	if (NULL == array)
	{
		ftlog__message(F, L,
			"ft_array$next_loop error: array ptr (null)",
			EINVAL);
		return (NULL);
	}
	if (array->length == 0)
		return (NULL);
	element = ftarray__at(array, array->i);
	{
		array->i =
			(array->i + 1 == array->length) ?
			0 : array->i + 1;
	}
	return (element);
}

void	*ftarray__next(t_array *array)
{
	void *element;

	if (NULL == array)
	{
		ftlog__message(F, L,
			"ftarray__next error: array ptr (null)",
			EINVAL);
		return (NULL);
	}
	else if (array->i == array->length)
	{
		return (NULL);
	}
	else
	{
		element = ftarray__at(array, array->i);
		array->i += 1;
		return (element);
	}
}
