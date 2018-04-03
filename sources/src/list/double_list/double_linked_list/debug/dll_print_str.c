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

void dll_print_str(t_dll lst)
{
	t_dll_l link;

	link = lst->top;
	while (link)
	{
		ft_printf("%s ", link->content);
		link = link->next;
	}
	ft_printf(" -- end \n");
}

void dll_print_strrev(t_dll lst)
{
	t_dll_l link;

	link = lst->end;
	while (link)
	{
		ft_printf("%s ", link->content);
		link = link->prev;
	}
	ft_printf(" -- end \n");
}