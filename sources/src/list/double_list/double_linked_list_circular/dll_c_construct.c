/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_c_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:42:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../ft_library_header.h"

static void			destroy_all_links(t_dll_c list)
{
	t_dll_l	current_link;
	t_dll_l	next_link;
	size_t	i;

	i = list->length;
	if (i == 0)
		return ;
	current_link = list->top;
	while (i)
	{
		next_link = current_link->next;
		destroy_dll_l(&current_link);
		i -= 1;
		if (i != 0)
			current_link = next_link;
	}
	list->length = 0;
}

void				destroy_dll_c(t_dll_c *l)
{
	t_dll_c list;

	list = *l;
	destroy_all_links(list);
	list->top = NULL;
	free(list);
}

t_dll_c				new_dll_c(void)
{
	t_dll_c list;

	list = ft_malloc_protect(sizeof(t_dll_c_00));
	list->top = NULL;
	list->length = 0;
	return (list);
}
