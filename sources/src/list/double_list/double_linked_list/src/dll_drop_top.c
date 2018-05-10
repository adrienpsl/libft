/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_drop_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:38 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

t_dll_l	dll_drop_top(t_dll list)
{
	t_dll_l link;
	t_dll_l new_top;

	if (list->length == 0)
		return (NULL);
	else if (list->length == 1)
		return (dll_drop_list_one(list));
	link = list->top;
	new_top = list->top->next;
	list->top = new_top;
	new_top->prev = NULL;
	reset_ptr_dll_l(link);
	list->length -= 1;
	return (link);
}
