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

#include "../../../../../ft_library_header.h"

t_dll_l dll_drop_end(t_dll list)
{
	t_dll_l link;
	t_dll_l new_end;

	if (list->length == 0)
		return (NULL);
	else if (list->length == 1)
		return (dll_drop_list_one(list));
	link = list->end;
	new_end = list->end->prev;

	list->end = new_end;
	new_end->next = NULL;

	reset_ptr_dll_l(link);
	list->length -= 1;
	return (link);
}