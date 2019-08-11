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

#include <ft_mem.h>
#include "ft_array.h"
#include "includes/ft_array.bubble.h"

int
ft_array_bubble(t_array *array, int(*cmp_f)(void *, void *, int), int order)
{
	t_bubble b;

	ft_bzero(&b, sizeof(b));
	while (b.i < array->length - 1)
	{
		b.y = 0;
		b.sorted = 1;
		while (b.y < (array->length - b.i - 1))
		{
			if (cmp_f(ft_array_at(array, b.y),
					  ft_array_at(array, b.y + 1),
					  order))
			{
				b.sorted = 0;
				ft_mem_swap(ft_array_at(array, b.y),
							ft_array_at(array, b.y + 1), array->buffer,
							array->element_size);
			}
			b.y++;
		}
		if (b.sorted == 1)
			break;
		b.i++;
	}
	return (0);
}
