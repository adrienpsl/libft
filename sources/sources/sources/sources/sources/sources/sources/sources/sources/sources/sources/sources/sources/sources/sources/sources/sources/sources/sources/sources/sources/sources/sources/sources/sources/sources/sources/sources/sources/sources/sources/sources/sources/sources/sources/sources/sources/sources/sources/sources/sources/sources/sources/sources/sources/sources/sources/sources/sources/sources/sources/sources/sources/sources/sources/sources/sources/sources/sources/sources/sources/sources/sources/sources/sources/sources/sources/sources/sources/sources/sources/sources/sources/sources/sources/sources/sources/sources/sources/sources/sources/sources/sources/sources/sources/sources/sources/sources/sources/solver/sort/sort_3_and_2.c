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

void sort_2_top(t_stack stack)
{
	do_inst('p', NO, stack);
	do_inst('p', NO, stack);
	need_swap(stack);
}

void sort_2_end(t_stack stack)
{
	do_inst('a', NO, stack);
	do_inst('a', NO, stack);
	sort_2_top(stack);
}


void sort_3_top(t_stack stack)
{
	t_dll_c pile;

	pile = stack->currrent_pile_dll;

	sort_browser(stack, get_med(pile, 3), 3);

	need_swap(stack);

	if (stack->current_pile == 'B')
	{
		do_inst('a', NO, stack);
		do_inst('p', NO, stack);
		return;
	}
	do_inst('a', NO, stack);
	do_inst('a', NO, stack);
	need_swap(stack);
	do_inst('p',YES, stack);
}

void sort_3_end(t_stack stack)
{
	t_dll_c pile;


	if (stack->currrent_pile_dll->length == 3)
		return (sort_3_top(stack));
	pile = new_dll_c();
	pile->top = stack->current_pile == 'A' ?
				stack->pile_a->top->prev->prev->prev :
				stack->pile_b->top->prev->prev->prev;
	pile->length = 3;
	sort_browser_reverse(stack, get_med(pile, 3), 3);

	need_swap(stack);
	if (stack->current_pile == 'B')
		do_inst('p', NO, stack);
	else
		do_inst('p', YES, stack);

	free(pile);
}