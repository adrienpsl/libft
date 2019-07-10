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
/*
 * pay attention, the cmp function res is !!
 * */
static int partition(t_sort *quick, int low, int high)
{
	t_array *arr;
	int j;
	int i;
	void *pivot;

	arr = quick->array;
	pivot = ft_array_el(arr, high);
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (!quick->cmp_func(ft_array_el(arr, j), pivot, quick->param))
		{
			i++;
			quick->swap_func(ft_array_el(arr, i), ft_array_el(arr, j));
		}
		j++;
	}
	quick->swap_func(ft_array_el(arr, i + 1), ft_array_el(arr, high));
	return (i + 1);
}


int ft_quick_sort(t_sort *quick, int low, int high)
{
	if (low < high && low >= 0)
	{
		int pi = partition(quick, low, high);
		ft_quick_sort(quick, low, pi - 1);
		ft_quick_sort(quick, pi + 1, high);
	}
	return (0);
}

int ft_array_bubble(t_sort *s)
{
	size_t i;
	size_t y;
	void *el_1;
	void *el_2;

	i = 0;
	while (i < s->array->length - 1)
	{
		y = 0;
		s->sorted = 1;
		while (y < s->array->length - i - 1)
		{
			el_1 = ft_array_el(s->array, y);
			el_2 = ft_array_el(s->array, y + 1);
			if (s->cmp_func(el_1, el_2, s->param))
			{
				s->sorted = 0;
				s->swap_func(el_1, el_2);
			}
			y++;
		}
		if (s->sorted == 1)
			break;
		i++;
	}
	return (0);
}
