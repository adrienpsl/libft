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

void ftarray__clear(t_array *array)
{
	if (NULL == array)
	{
		ftlog__message(F, L,
					   "ft_array$clear arg ptr (null)",
					   EINVAL
		);
		return ;
	}
	ft_bzero(array->data, array->length * array->element_size);
	array->length = 0;
}

