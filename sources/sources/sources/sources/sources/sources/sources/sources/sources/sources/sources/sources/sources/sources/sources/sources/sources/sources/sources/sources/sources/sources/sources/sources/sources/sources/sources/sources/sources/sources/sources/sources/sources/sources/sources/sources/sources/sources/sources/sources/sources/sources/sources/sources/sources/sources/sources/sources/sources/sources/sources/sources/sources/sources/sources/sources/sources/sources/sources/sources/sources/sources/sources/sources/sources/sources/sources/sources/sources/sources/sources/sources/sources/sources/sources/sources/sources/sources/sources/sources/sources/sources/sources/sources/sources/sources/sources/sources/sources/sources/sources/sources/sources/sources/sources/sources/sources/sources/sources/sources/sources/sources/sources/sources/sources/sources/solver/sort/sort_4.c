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

static void browser_end(t_stack stack)
{
	do_inst('a', NO, stack);
	do_inst('a', NO, stack);
	need_swap(stack);
	if (stack->current_pile == 'A')
	{
		do_inst('p', YES, stack);
		do_inst('p', YES, stack);
	}
	else
	{
		do_inst('p', NO, stack);
		do_inst('p', NO, stack);
	}
}

void sort_4_top(t_stack stack)
{
	t_dll_c pile;

	pile = stack->currrent_pile_dll;
	sort_browser(stack, get_med(pile, 4), 4);
	browser_end(stack);
}

static void browser_reverse_end(t_stack stack)
{
	need_swap(stack);
	if (stack->current_pile == 'A')
	{
		do_inst('p', YES, stack);
		do_inst('p', YES, stack);
	}
	else
	{
		do_inst('p', NO, stack);
		do_inst('p', NO, stack);
	}
}

void sort_4_end(t_stack stack)
{
	t_dll_c pile;

	pile = new_dll_c();

	pile->top = stack->current_pile == 'A' ?
				stack->pile_a->top->prev->prev->prev->prev :
				stack->pile_b->top->prev->prev->prev->prev;
	pile->length = 4;
	sort_browser_reverse(stack, get_med(pile, 4), 4);
	browser_reverse_end(stack);
	free(pile);
}