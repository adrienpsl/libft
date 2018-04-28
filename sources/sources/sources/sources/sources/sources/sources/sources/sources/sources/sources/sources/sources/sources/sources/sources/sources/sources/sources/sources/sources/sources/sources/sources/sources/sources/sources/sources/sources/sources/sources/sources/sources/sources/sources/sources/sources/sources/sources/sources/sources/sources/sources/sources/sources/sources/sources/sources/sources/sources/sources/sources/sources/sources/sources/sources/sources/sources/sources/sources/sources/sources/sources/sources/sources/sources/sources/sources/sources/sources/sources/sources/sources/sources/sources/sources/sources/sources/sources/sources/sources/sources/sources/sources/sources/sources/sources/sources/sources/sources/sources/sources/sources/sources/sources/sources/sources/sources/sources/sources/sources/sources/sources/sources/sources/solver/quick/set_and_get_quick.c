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

#include "../../../header/all_includes.h"

void placed_quick_by_sort(t_stack stack)
{
	t_dll_l link;
	size_t  lim;

	lim = stack->quick.counter_quick;
	link = stack->pile_a->top;
	while (lim > 0)
	{
		((t_data) link->content)->quick = 0;
		link = link->next;
		lim--;
	}
}



int reset_quick_1(t_stack stack)
{
	t_dll_l link;

	link = stack->current_pile == 'A' ? stack->pile_a->top : stack->pile_b->top;
	((t_data) link->content)->quick = stack->browse.quick_count + 1;
	return (1);
}

int reset_quick(t_stack stack)
{
	t_dll_l link;

	link = stack->current_pile == 'A' ? stack->pile_a->top : stack->pile_b->top;
	((t_data) link->content)->quick = stack->browse.quick_count;
	return (1);
}

int get_quick(t_dll_l link)
{
	return (((t_data) link->content)->quick);
}

void set_quick(t_stack stack)
{
	t_dll_l link;

	link = stack->current_pile == 'A' ? stack->pile_a->top : stack->pile_b->top;
	if (((t_data) link->content)->quick == 0)
		((t_data) link->content)->quick = stack->browse.quick_count;
}

void set_quick_1(t_stack stack)
{
	t_dll_l link;

	link = stack->current_pile == 'A' ? stack->pile_a->top : stack->pile_b->top;
	if (((t_data) link->content)->quick == 0)
		((t_data) link->content)->quick = stack->browse.quick_count + 1;
}