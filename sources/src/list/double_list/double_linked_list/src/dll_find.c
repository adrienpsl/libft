/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:23:40 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

t_dll_l	dll_find(t_dll list, int (*func)(t_dll_l, void*), void *ptr)
{
	t_dll_l link;

	link = list->top;
	while (link)
	{
		if (func(link, ptr) == TRUE)
			return (link);
		link = link->next;
	}
	return (FALSE);
}
