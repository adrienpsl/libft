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
#include "ft_errno.h"
#include "ft_array.h"

t_array *ftarray__copy(
	t_array *src)
{
	if (NULL == src)
	{
		ftlog__message(F, L, "ft_array$copy error: array ptr (null)",
			EINVAL);
		return (NULL);
	}
	return (ftarray__init_data(src->data,
		src->length,
		src->element_size));
}

t_array *ftarray__copy_func(
	t_array *src,
	int(*f)(void *, void *, void *),
	void *param)
{
	t_array *new;
	int i;

	i = 0;
	if (NULL == src || NULL == f)
	{
		ftlog__message(F, L, "ft__array_copy_func error: ptr (null)",
			EINVAL);
		return (NULL);
	}
	if (NULL == (new = ftarray__init(src->length, src->element_size)))
		return (NULL);
	while (i < src->length)
	{
		if (OK == f(ftarray__at(new, i), ftarray__at(src, i), param))
			new->length += 1;
		else
			return (NULL);
		i++;
	}
	return (new);
}
