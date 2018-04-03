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

t_dll_l dll_add(t_dll_l link, t_dll list)
{
	t_dll_l prev_link;

	if (link == NULL)
		return (link);
	else if (list->length == 0)
		return (dll_list_empty(link, list));

	prev_link = list->end;
	prev_link->next = link;
	link->prev = prev_link;

	list->end = link;
	list->length += 1;
	return (link);
}
