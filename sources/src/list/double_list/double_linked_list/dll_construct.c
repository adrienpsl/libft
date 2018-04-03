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

static void destroy_all_links(t_dll list)
{
	t_dll_l current_link;
	t_dll_l next_link;

	current_link = list->top;
	while (current_link)
	{
		next_link = current_link->next;
		destroy_dll_l(&current_link);
		current_link = next_link;
	}
	list->length = 0;
}

void destroy_dll(t_dll *l)
{
	t_dll list;

	list = *l;
	destroy_all_links(list);
	list->top = NULL;
	list->end = NULL;
	free(list);
}

t_dll new_dll()
{
	t_dll list;

	list = ft_malloc_protect(sizeof(struct s_dll));
	list->top = NULL;
	list->length = 0;
	return (list);
}