/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_fill_list_circular.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:37 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

void	dll_fill_list_circular(t_dll_c c_list, t_dll list, size_t lenght)
{
	int		nb;
	size_t	i;
	t_dll_l	new_link;
	t_dll_l	link;

	i = 0;
	link = c_list->top;
	while (i < lenght)
	{
		nb = dll_l_get_int(link);
		new_link = new_dll_l(&nb, sizeof(int));
		dll_add(new_link, list);
		link = link->next;
		++i;
	}
}
