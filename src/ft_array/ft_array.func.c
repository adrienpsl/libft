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

int ft_array_func_print$str(void *p1, void *p2, void *p3)
{
	(void) p2;
	(void) p3;
	(void) p1;
	ft_printf("-%s- ", p1);
	return (0);
}

void *ft_array_func(t_array *array,
int(*f)(void *, void *),
void *param)
{
	int i;

	if (!array)
		return NULL;
	i = 0;
	while (i < array->length)
	{
		if (f(ft_array_at(array, i), param))
			return (ft_array_at(array, i));
		i++;
	}
	return (NULL);
}
