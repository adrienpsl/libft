/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_c_add_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:39:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

static void		one_el(t_dll_l link)
{
	link->next = link;
	link->prev = link;
}

static void		two_el(t_dll_l link, t_dll_c c_list)
{
	t_dll_l top_link;

	top_link = c_list->top;
	top_link->next = link;
	top_link->prev = link;
	link->next = top_link;
	link->prev = top_link;
}

static void		more_two(t_dll_l link, t_dll_c c_list)
{
	t_dll_l top_link;
	t_dll_l prev_link;

	top_link = c_list->top;
	prev_link = top_link->prev;
	top_link->prev = link;
	link->next = top_link;
	prev_link->next = link;
	link->prev = prev_link;
}

t_dll_l			dll_c_add_after(t_dll_l link, t_dll_c c_list)
{
	if (link == NULL)
		return (NULL);
	else if (c_list->length == 0)
	{
		one_el(link);
		c_list->top = link;
	}
	else if (c_list->length == 1)
		two_el(link, c_list);
	else
		more_two(link, c_list);
	c_list->length += 1;
	return (link);
}
