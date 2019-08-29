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
#include <ft_mem.h>
#include "ft_array.h"

static int
check(t_array **array, void (*f)(void *, void *))
{
	if (NULL == array || NULL == *array)
	{
		return (
			ftlog__message(F, L,
						   "ftarray__free_func error: array ptr (null)",
						   EINVAL));
	}
	if (!f)
	{
		return (
			ftlog__message(F, L,
						   "ftarray__free_func error: func ptr (null)",
						   EINVAL));
	}
	return (0);
}

void
ftarray__free_func(t_array **p_array, void (*f)(void *, void *), void *param)
{
	void *current_element;

	if (check(p_array, f))
		return;
	ftarray__set_start(*p_array);
	while (
		(current_element = ftarray__next(*p_array))
		)
		f(current_element, param);
	ftarray__clear(*p_array);
	ft_bzero(*p_array, sizeof(t_array));
	free(*p_array);
	*p_array = NULL;
}
