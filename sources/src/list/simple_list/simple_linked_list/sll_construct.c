/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../ft_library_header.h"

static void		destroy_all_links(t_sll list)
{
	t_sll_l top;
	t_sll_l next;

	top = list->top;
	while (top != NULL)
	{
		next = top->next;
		destroy_sll_l(&top);
		top = next;
	}
	list->lenght = 0;
}

void			destroy_sll(t_sll *l)
{
	t_sll sll;

	sll = *l;
	destroy_all_links(sll);
	sll->top = NULL;
	free(sll);
}

t_sll			new_sll(void)
{
	t_sll list;

	list = ft_malloc_protect(sizeof(t_sll_00));
	ft_memset(list, 0, sizeof(t_sll_00));
	return (list);
}
