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

void sll_print_str(t_sll list)
{
	t_sll_l link;

	link = list->top;

	while (link)
	{
	    ft_printf("%s ", link->content);
	    link = link->next;
	}
	ft_printf(" ||\n");
}

void sll_print_str_link(t_sll_l link)
{
	while (link)
	{
		ft_printf("%s ", link->content);
		link = link->next;
	}
	ft_printf(" ||\n");
}