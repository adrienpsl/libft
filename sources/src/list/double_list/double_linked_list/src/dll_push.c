/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:35 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

t_dll_l	dll_push(t_dll_l link, t_dll list)
{
	t_dll_l prev_link;

	if (link == NULL)
		return (link);
	else if (list->length == 0)
		return (dll_list_empty(link, list));
	prev_link = list->top;
	prev_link->prev = link;
	link->next = prev_link;
	list->top = link;
	list->length += 1;
	return (link);
}
