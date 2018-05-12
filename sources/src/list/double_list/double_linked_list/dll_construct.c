/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:29:11 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../ft_library_header.h"

static void		destroy_all_links(t_dll list)
{
	t_dll_l current_link;
	t_dll_l next_link;

	if (list->top == NULL)
		return ;
	current_link = list->top;
	while (current_link)
	{
		next_link = current_link->next;
		destroy_dll_l(&current_link);
		current_link = next_link;
	}
	list->length = 0;
}

void			destroy_dll_func(t_dll *l, void (*func) (t_dll_l))
{
	t_dll	list;
	t_dll_l	current_link;
	t_dll_l	next_link;

	list = *l;
	current_link = list->top;
	while (current_link)
	{
		next_link = current_link->next;
		destroy_dll_l_func(&current_link, func);
		current_link = next_link;
	}
	list->length = 0;
	list->top = NULL;
	list->end = NULL;
	free(list);
}

void			destroy_dll(t_dll *l)
{
	t_dll list;

	list = *l;
	destroy_all_links(list);
	list->top = NULL;
	list->end = NULL;
	free(list);
}

t_dll			new_dll(void)
{
	t_dll list;

	list = ft_malloc_protect(sizeof(t_dll_00));
	list->top = NULL;
	list->length = 0;
	return (list);
}
