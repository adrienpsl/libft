/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:35 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

void	dll_print_nb(t_dll lst)
{
	t_dll_l link;

	link = lst->top;
	while (link)
	{
		ft_printf("%2d ", dll_l_get_int(link));
		link = link->next;
	}
	ft_printf("\n");
}

void	dll_print_nbrev(t_dll lst)
{
	t_dll_l link;

	link = lst->end;
	while (link)
	{
		ft_printf("%2d ", dll_l_get_int(link));
		link = link->prev;
	}
	ft_printf("\n");
}
