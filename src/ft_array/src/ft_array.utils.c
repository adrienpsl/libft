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
#include "ft_mem.h"
#include "ft_array.h"

void	ftarray__clear(t_array *array)
{
	if (NULL == array)
	{
		ftlog__message(F, L,
			"ftarray__clear arg ptr (null)",
			EINVAL);
		return ;
	}
	ft_bzero(array->data, array->length * array->element_size);
	array->length = 0;
}

void	ftarray__set_start(t_array *array)
{
	if (NULL == array)
	{
		ftlog__message(F, L,
			"ftarray__set_start arg ptr (null)",
			EINVAL);
		return ;
	}
	array->i = 0;
}

int		ftarray__remain(t_array *array)
{
	return (array->length - array->i);
}

void	*ftarray__current(t_array *array)
{
	return (ftarray__at(array, array->i));
}
