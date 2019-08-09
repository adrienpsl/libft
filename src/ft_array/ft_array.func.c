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

int ft_array_func_print$str(void *p1, void *param)
{
	(void) param;
	ft_printf(" _%s_ ", p1);
	return (0);
}

int ft_array_func_print$int(void *p1, void *param)
{
	(void) param;
	ft_printf("%d", p1);
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
