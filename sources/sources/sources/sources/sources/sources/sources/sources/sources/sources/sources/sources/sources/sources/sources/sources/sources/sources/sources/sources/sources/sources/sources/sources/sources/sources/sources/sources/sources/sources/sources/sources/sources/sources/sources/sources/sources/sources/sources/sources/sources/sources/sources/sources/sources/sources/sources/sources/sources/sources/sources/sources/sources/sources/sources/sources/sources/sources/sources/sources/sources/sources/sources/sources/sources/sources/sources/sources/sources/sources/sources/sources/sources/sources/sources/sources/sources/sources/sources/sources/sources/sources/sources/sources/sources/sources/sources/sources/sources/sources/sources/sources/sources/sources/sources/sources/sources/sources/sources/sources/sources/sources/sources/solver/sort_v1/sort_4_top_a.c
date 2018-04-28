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

void abab_sort4top_a(t_stack stack)
{
	do_inst('p', NO, stack);
	do_inst('s', NO, stack);
	if (is_ordered_link(stack->pile_a->top->next, 2))
	{
		do_inst('p', YES, stack);
		need_swap(stack);
	}
	else
	{
		do_inst('p', NO, stack);
		need_swap(stack);
		do_inst('p', YES, stack);
		do_inst('p', YES, stack);
	}
}

void baab_sort4top_a(t_stack stack)
{
	do_inst('s', NO, stack);
	abab_sort4top_a(stack);
}

// optimisation si les deux b sont ok
static void end_1(t_stack stack)
{
	do_inst('s', NO, stack);
	do_inst('p', NO, stack);
	do_inst('a', NO, stack);
	need_swap(stack);
	do_inst('p', YES, stack);
	do_inst('p', YES, stack);
}
void abba_sort4top_a(t_stack stack)
{
	do_inst('p', NO, stack);
	do_inst('r', NO, stack);
	end_1(stack);
}

void baba_sort4top_a(t_stack stack)
{
	do_inst('r', NO, stack);
	do_inst('p', NO, stack);
	end_1(stack);
}