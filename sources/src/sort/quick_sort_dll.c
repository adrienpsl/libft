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

#include "../../ft_library_header.h"

int ddl_is_top(t_dll list, t_dll_l link)
{
	return (link == list->top);
}

int ddl_is_end(t_dll list, t_dll_l link)
{
	return (link == list->end);
}

int dll_l_is_bigger(t_dll_l a, t_dll_l b)
{
	return (dll_l_get_int(a) > dll_l_get_int(b));
}

int dll_l_is_lower(t_dll_l a, t_dll_l b)
{
	return (dll_l_get_int(a) < dll_l_get_int(b));
}

static void swap(t_dll_l a, t_dll_l b)
{
	int temp;

	temp = dll_l_get_int(a);
	*(int *) a->content = *(int *) b->content;
	*(int *) b->content = temp;
}

void ft_quick_sort_dll(t_dll_l start, t_dll_l end, t_dll list)
{
	t_dll_l left;
	t_dll_l right;
	t_dll_l pivot;

	if (start == end)
		return;
	pivot = start;
	left = start;
	right = end;
	while (1)
	{
		while (dll_l_is_lower(left, pivot))
		{
			left = left->next;
		}
		while (dll_l_is_bigger(right, pivot))
		{
			right = right->prev;
		}
		if (left < right)
		{
			swap(left, right);
			dll_print_nb(list);
		}
		else
			break;
	}
	ft_quick_sort_dll(start, right, list);
	ft_quick_sort_dll(right->next, end, list);
}