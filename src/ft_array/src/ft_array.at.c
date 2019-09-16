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

void	*ftarray__at(t_array *array, int index)
{
	if (!array)
	{
		ftlog__message(F, L,
			"ft_array$at error: array ptr (null)",
			EINVAL);
		return (NULL);
	}
	else if (index >= array->capacity)
	{
		ftlog__message(F, L,
			"ft_array$at error : index bigger than length",
			EINVAL);
		return (NULL);
	}
	else if (index < 0)
	{
		ftlog__message(F, L,
			"ft_array$at error : index is negative",
			EINVAL);
		return (NULL);
	}
	else
	{
		return (array->data + (index * array->element_size));
	}
}
