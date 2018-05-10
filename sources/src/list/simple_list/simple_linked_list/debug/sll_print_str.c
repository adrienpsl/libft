/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_print_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:46:46 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

void	sll_print_str(t_sll list)
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

void	sll_print_str_link(t_sll_l link)
{
	while (link)
	{
		ft_printf("%s ", link->content);
		link = link->next;
	}
	ft_printf(" ||\n");
}
