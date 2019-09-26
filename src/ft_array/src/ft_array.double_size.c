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

#include "libft.h"

int					ftarray__double_size(t_array *array)
{
	void	*data;
	int		new_capacity;

	if (NULL == array)
	{
		ftlog__message(F, L, "ftarray__double_size error: array ptr (null)",
			EINVAL);
		return (-1);
	}
	new_capacity = array->length * 2;
	if (NULL ==
		(data = ft_memalloc(array->element_size * (new_capacity + 1))))
		return (-1);
	ft_memcpy(data, array->data,
		(array->length * array->element_size));
	ft_bzero(array->data, array->length * array->element_size);
	free(array->data);
	array->capacity = new_capacity;
	array->data = data;
	return (0);
}
