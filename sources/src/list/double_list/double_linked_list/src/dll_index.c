/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:36 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

static t_dll_l	push_index(t_dll_l link, t_dll list, size_t index)
{
	t_dll_l prev_link;
	t_dll_l next_link;

	next_link = get_good_link(index, list);
	prev_link = next_link->prev;
	link->next = next_link;
	next_link->prev = link;
	link->prev = prev_link;
	prev_link->next = link;
	list->length += 1;
	return (link);
}

t_dll_l			dll_index(t_dll_l link, t_dll list, size_t index)
{
	if (link == NULL)
		return (link);
	else if (list->length == 0)
		return (dll_list_empty(link, list));
	else if (index == 0)
		return (dll_push(link, list));
	else if (index >= list->length)
		return (dll_add(link, list));
	return (push_index(link, list, index));
}
