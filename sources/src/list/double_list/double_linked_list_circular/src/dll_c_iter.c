/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_c_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:39:48 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

t_dll_l		dll_l_iter_int(t_dll_c c_list, int nb, int (*func)(int, int))
{
	size_t	i;
	t_dll_l	current_link;

	if (c_list->length == 0)
		return (NULL);
	i = c_list->length;
	current_link = c_list->top;
	while (i != 0)
	{
		if (func(dll_l_get_int(current_link), nb))
			return (current_link);
		current_link = current_link->next;
		i--;
	}
	return (NULL);
}
