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
#include <errno.h>
# include "ft_array.h"

static int check(t_array *a_1, t_array *a_2, int (*f)(void *, void *))
{
	if (!a_1 || !a_2)
	{
		return (
			ftlog__message(F, L,
						   "ft_array$cmp error: array ptr (null)",
						   EINVAL)
		);
	}
	else if (!f)
	{
		return (
			ftlog__message(F, L,
						   "ft_array$cmp error: func ptr (null)",
						   EINVAL)
		);
	}
	return (0);
}

int ftarray__cmp(t_array *array_1, t_array *array_2, int (*f)(void *, void *))
{
	void *el_1;
	void *el_2;

	if (
		check(array_1, array_2, f)
		)
		return (-1);
	array_1->i = 0;
	array_2->i = 0;
	while ((el_1 = ftarray__next(array_1))
		   && (el_2 = ftarray__next(array_2)))
	{
		if (f(el_1, el_2))
			return (1);
	}
	el_2 = ftarray__next(array_2);
	if (el_1 != el_2)
		return (1);
	return (0);
}
