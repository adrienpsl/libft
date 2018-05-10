/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_c_push_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:36:49 by adpusel          ###   ########.fr       */
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
	t_dll_l placed_link;

	placed_link = c_list->top;
	placed_link->next = link;
	placed_link->prev = link;
	link->next = placed_link;
	link->prev = placed_link;
}

static void		more_two(t_dll_l link, t_dll_c c_list)
{
	t_dll_l next_link;
	t_dll_l prev_link;

	next_link = c_list->top;
	prev_link = next_link->prev;
	next_link->prev = link;
	link->next = next_link;
	prev_link->next = link;
	link->prev = prev_link;
}

t_dll_l			dll_c_push_link(t_dll_l link, t_dll_c c_list)
{
	if (link == NULL)
		return (NULL);
	else if (c_list->length == 0)
		one_el(link);
	else if (c_list->length == 1)
		two_el(link, c_list);
	else
		more_two(link, c_list);
	c_list->top = link;
	c_list->length += 1;
	return (link);
}
