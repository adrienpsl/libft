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

#include <ft_mem.h>
#include <errno.h>
#include <ft_log.h>
#include "ft_array.h"

int	static			check(
	t_array *array,
	int (*cmp_f)(void *, void *, void *))
{
	if (NULL == array)
		return (
			ftlog__message(F, L,
				"ft_array$sort_bubble error: array ptr (null)",
				EINVAL));
	if (NULL == cmp_f)
		return (
			ftlog__message(F, L,
				"ft_array$sort_bubble error: func ptr (null)",
				EINVAL));
	return (0);
}

static int			make_a_pass(
	t_array *array,
	int(*cmp_f)(void *, void *, void *),
	void *param,
	int *i)
{
	int y;
	int is_sorted;

	y = 0;
	is_sorted = 1;
	while (y < (array->length - *i - 1))
	{
		if (cmp_f(ftarray__at(array, y),
				ftarray__at(array, y + 1),
				param))
		{
			is_sorted = 0;
			ft_mem_swap(
				ftarray__at(array, y),
				ftarray__at(array, y + 1), array->buffer,
				array->element_size);
		}
		y++;
	}
	return (is_sorted);
}

int					ftarray__sort_bubble(
	t_array *array,
	int(*cmp_f)(void *, void *, void *),
	void *param)
{
	int i;

	if (check(array, cmp_f))
		return (-1);
	i = 0;
	while (i < array->length - 1)
	{
		if (make_a_pass(array, cmp_f, param, &i))
			break;
		i++;
	}
	return (0);
}
