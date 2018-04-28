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

void placed_quick(t_dll_l link, size_t lim)
{
	while (lim > 0)
	{
		((t_data) link->content)->quick = 0;
		link = link->next;
		lim--;
	}
}

void quick_get_good_pile(t_stack stack)
{
	int quick_a;
	int quick_b;
	t_quick *quick;

	quick = &stack->quick;

	quick_a = get_quick(stack->pile_a->top);
	if (get_quick(stack->pile_a->top->prev) > quick_a)
		quick_a = get_quick(stack->pile_a->top->prev);

	quick_b = get_quick(stack->pile_b->top);
	if (get_quick(stack->pile_b->top->prev) > quick_b)
		quick_b = get_quick(stack->pile_b->top->prev);

	set_stack(quick_a > quick_b ? 'A' : 'B', stack);
	quick->sens = get_quick(stack->currrent_pile_dll->top) >
				  get_quick(stack->currrent_pile_dll->top->prev) ?
				  'T' : 'E';
	quick->quick = quick_a > quick_b ? quick_a : quick_b;
}

void update_quick(t_stack stack)
{
	ft_memset(&stack->quick, 0, sizeof(t_quick));
	if (stack->pile_b->length)
	{
		quick_get_good_pile(stack);
		count_quick(stack);
	}
}

long count_quick(t_stack stack)
{
	long size;
	int current_quick;
	int quick_searched;
	t_dll_l link;
	t_dll_c pile;
	char sens;

	sens = stack->quick.sens;
	pile = stack->currrent_pile_dll;
	size = 0;
	link = sens == 'T' ? pile->top : pile->top->prev;
	current_quick = get_quick(link);
	(void) 1;
	quick_searched = stack->quick.quick;
	while (current_quick == quick_searched && (size_t) size < pile->length)
	{
		link = sens == 'T' ? link->next : link->prev;
		current_quick = get_quick(link);
		size++;
	}
	stack->quick.counter_quick = size;
	return (size);
}

