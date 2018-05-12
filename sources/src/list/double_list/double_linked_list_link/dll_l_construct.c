/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_l_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:31:01 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../ft_library_header.h"

void		reset_ptr_dll_l(t_dll_l link)
{
	link->next = NULL;
	link->prev = NULL;
}

void		destroy_dll_l_func(t_dll_l *l, void (*func) (t_dll_l))
{
	t_dll_l link;

	link = *l;
	if (link->content)
	{
		func(link);
		link->content = NULL;
	}
	link->prev = NULL;
	link->next = NULL;
	free(link);
}

void		destroy_dll_l(t_dll_l *l)
{
	t_dll_l link;

	link = *l;
	if (link->content)
	{
		free(link->content);
		link->content = NULL;
	}
	link->prev = NULL;
	link->next = NULL;
	free(link);
}

t_dll_l		new_dll_l(void *content, size_t size)
{
	t_dll_l link;

	link = (t_dll_l)ft_malloc_protect(sizeof(t_dll_l_00));
	link->content = ft_malloc_protect(size);
	if (content != NULL)
		ft_memcpy(link->content, content, size);
	link->content_size = size;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}
