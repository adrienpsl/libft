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

int ft_array_cmp$int(void *p1, void *p2)
{
	int *a;
	int *b;

	a = p1;
	b = p2;
	return (!(*a == *b));
}

int ft_array_cmp$str(void *p1, void *p2)
{
	char *a;
	char *b;

	a = p1;
	b = p2;
	return (!ft_streq(a, b));
}

int ft_array_cmp(t_array *array_1, t_array *array_2, int (*f)(void *, void *))
{
	void *el_1;
	void *el_2;

	if (!array_1 || !array_2)
		return (1);
	array_1->i = 0;
	array_2->i = 0;
	while ((el_1 = ft_array_next(array_1))
		   && (el_2 = ft_array_next(array_2)))
	{
		if (f && f(el_1, el_2))
			return (1);
	}
	el_2 = ft_array_next(array_2);
	if (el_1 != el_2)
		return (1);
	return (0);
}
