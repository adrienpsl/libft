/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_c_drop_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:37:41 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

static t_dll_l		one_el(t_dll_c c_list)
{
	t_dll_l link;

	link = c_list->top;
	reset_ptr_dll_l(link);
	c_list->top = NULL;
	return (link);
}

static t_dll_l		two_el(t_dll_c c_list)
{
	t_dll_l link;
	t_dll_l link_in_c_list;

	link = c_list->top;
	link_in_c_list = link->next;
	c_list->top = link_in_c_list;
	link_in_c_list->next = link_in_c_list;
	link_in_c_list->prev = link_in_c_list;
	return (link);
}

static t_dll_l		more_two(t_dll_c c_list)
{
	t_dll_l drop_link;
	t_dll_l new_top;
	t_dll_l prev_link;

	drop_link = c_list->top;
	new_top = drop_link->next;
	prev_link = drop_link->prev;
	reset_ptr_dll_l(drop_link);
	new_top->prev = prev_link;
	prev_link->next = new_top;
	c_list->top = new_top;
	return (drop_link);
}

t_dll_l				dll_c_drop_link(t_dll_c c_list)
{
	t_dll_l link;

	if (c_list->length == 0)
		return (NULL);
	else if (c_list->length == 1)
		link = one_el(c_list);
	else if (c_list->length == 2)
		link = two_el(c_list);
	else
		link = more_two(c_list);
	c_list->length -= 1;
	return (link);
}
