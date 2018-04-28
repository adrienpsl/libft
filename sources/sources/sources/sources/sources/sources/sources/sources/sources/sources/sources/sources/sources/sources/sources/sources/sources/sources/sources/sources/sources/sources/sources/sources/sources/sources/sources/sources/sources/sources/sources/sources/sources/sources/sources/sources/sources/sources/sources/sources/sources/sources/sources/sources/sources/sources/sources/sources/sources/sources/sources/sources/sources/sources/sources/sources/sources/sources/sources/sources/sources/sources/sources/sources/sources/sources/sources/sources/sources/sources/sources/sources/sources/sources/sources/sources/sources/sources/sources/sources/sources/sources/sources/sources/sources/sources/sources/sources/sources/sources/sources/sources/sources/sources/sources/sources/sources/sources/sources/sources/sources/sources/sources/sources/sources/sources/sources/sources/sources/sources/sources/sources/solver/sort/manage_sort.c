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

void is44(t_stack stack)
{
	stack->quick.sens == 'T' ?
	sort_4_top(stack) :
	sort_4_end(stack);
}

void is33(t_stack stack)
{
	stack->quick.sens == 'T' ?
	sort_3_top(stack) :
	sort_3_end(stack);
}

void is22(t_stack stack)
{
	stack->quick.sens == 'T' ?
	sort_2_top(stack) :
	sort_2_end(stack);
}

void manage_all_short(t_stack stack)
{
	t_quick *quick;

	quick = &stack->quick;
	update_quick(stack);

	while (quick->counter_quick < 5 && stack->pile_b->length)
	{
		if (quick->counter_quick == 4)
			is44(stack);
		else if (quick->counter_quick == 3)
			is33(stack);
		else if (quick->counter_quick == 2)
			is22(stack);
		//		print_stack(stack);
		placed_quick_by_sort(stack);
		update_quick(stack);
	}
}