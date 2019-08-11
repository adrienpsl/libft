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

#include "ft_array.h"

void *ft_array_at(t_array *array, int index)
{
	if (!array || index >= array->capacity)
	{
		ft_errno_set(EINVAL, -1);
		// TODO :
		//		ft_logerror("ft_array_at error : index bigger than capacity");
		return (NULL);
	}
	else
		return (array->data + (index * array->element_size));
}