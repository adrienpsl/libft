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

#include "../../../../ft_library_header.h"

# define TOP_LIST 1
# define END_LIST 2

static int to_top_or_end(size_t index, t_dll list)
{
	size_t size_list;
	size_t middle_lenght_list;

	size_list = list->length;
	middle_lenght_list = size_list / 2;
	if (index <= middle_lenght_list)
		return (TOP_LIST);
	else
		return (END_LIST);
}

t_dll_l get_good_link(size_t index, t_dll list)
{
	t_dll_l good_link;
	size_t direction;

	direction = to_top_or_end(index, list);
	if (direction == TOP_LIST)
	{
		good_link = list->top;
		while (index > 0)
		{
			good_link = good_link->next;
			index -= 1;
		}
	}
	else
	{
		good_link = list->end;
		index = list->length - index;
		while (index > 1)
		{
			good_link = good_link->prev;
			index -= 1;
		}
	}
	return (good_link);
}

t_dll_l dll_list_empty(t_dll_l link, t_dll list)
{
	list->top = link;
	list->end = link;
	list->length += 1;
	return (link);
}

t_dll_l dll_drop_list_one(t_dll list)
{
	t_dll_l link;

	link = list->top;
	list->top = NULL;
	list->end = NULL;
	list->length -= 1;
	return (link);
}