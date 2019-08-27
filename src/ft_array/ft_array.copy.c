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

t_array *ftarray__copy(t_array *src)
{
	if (NULL == src)
	{
		ftlog__message(F, L, "ft_array$copy error: array ptr (null)",
					   EINVAL);
		return (NULL);
	}
	return (ftarray__init_data(src->data,
							   (src->capacity / 2),
							   src->element_size));
}
