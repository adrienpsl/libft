/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_c_copie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:41:53 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

void	dll_c_copie(t_dll_c dest, t_dll_c src, size_t size)
{
	t_dll_l link;
	t_dll_l link_copie;

	link = src->top;
	while (size > 0)
	{
		link_copie = new_dll_l(link->content, link->content_size);
		dll_c_add_after(link_copie, dest);
		size--;
		link = link->next;
	}
}

void	dll_link_copie_reverse(t_dll_l link, t_dll_c list_2, size_t size)
{
	t_dll_l link_copie;

	while (size > 0)
	{
		link_copie = new_dll_l(link->content, link->content_size);
		dll_c_add_after(link_copie, list_2);
		size--;
		link = link->prev;
	}
}
