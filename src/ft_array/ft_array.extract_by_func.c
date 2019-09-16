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
#include <errno.h>
#include <ft_log.h>

static int check(t_array *array, int (*f)(void *, void *))
{
	if (
		NULL == array
		)
		return (
			ftlog__message(F, L,
				"ft_array__extract_by_func"
				" error: array ptr (null)",
				EINVAL));
	if (
		NULL == f
		)
		return (
			ftlog__message(F, L,
				"ft_array__extract_by_func"
				" error: func ptr (null)",
				EINVAL));
	return (0);
}

static void
loop_on_array(t_array *array, t_array *new, int(*f)(void *, void *),
	void *param)
{
	int i;

	i = 0;
	while (
		i < array->length
		)
	{
		if (
			f(ftarray__at(array, i), param)
			)
		{
			ftarray__push(new, ftarray__at(array, i));
			ftarray__remove(array, i);
		}
		else
			i++;
	}
}

t_array *
ftarray__extract_by_func(t_array *array, int(*f)(void *, void *), void *param)
{
	t_array *new;

	if (
		check(array, f)
		)
		return (NULL);
	if (
		NULL == (new = ftarray__init(array->length, array->element_size))
		)
		return (NULL);
	{
		loop_on_array(array, new, f, param);
	}
	return (new);
}





