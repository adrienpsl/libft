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
# include <stdio.h>

int ft_array_func_print$str(void *p1, void *param)
{
	(void) param;
	printf(" _%s_ ", *(char **) p1);
	return (0);
}

// TODO : delete printf
int ft_array_func_print$int(void *p1, void *param)
{
	(void) param;
	printf("%3d ", *(int *) p1);
	return (0);
}

void *ft_array_func(
	t_array *array,
	int(*func)(void *, void *),
	void *param
)
{
	int i;

	if (!array)
	{
		return NULL;
	}
	i = 0;
	while (i < array->length)
	{
		if (func(ft_array$at(array, i), param))
		{
			return (ft_array$at(array, i));
		}
		i++;
	}
	return (NULL);
}
