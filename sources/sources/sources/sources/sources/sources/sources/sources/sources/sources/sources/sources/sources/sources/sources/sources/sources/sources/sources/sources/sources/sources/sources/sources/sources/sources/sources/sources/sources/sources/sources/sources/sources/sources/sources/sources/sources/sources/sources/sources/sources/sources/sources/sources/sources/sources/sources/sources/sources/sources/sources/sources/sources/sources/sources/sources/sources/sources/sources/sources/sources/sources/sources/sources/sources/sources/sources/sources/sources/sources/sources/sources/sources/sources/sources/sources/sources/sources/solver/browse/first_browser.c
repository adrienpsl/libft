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

void push_by_median_push(int nb_top_pile, int med_push, t_stack stack)
{
	if (nb_top_pile >= med_push)
	{
		set_quick_1(stack);
		do_inst('p', NO, stack);
	}
	else
	{
		set_quick(stack);
		do_inst('p', NO, stack);
		do_inst('r', YES, stack);
	}
}

void browse_push(t_stack stack, int nb_top_pile)
{
	t_med med;
	t_browse *browse;

	med = stack->med;
	browse = &stack->browse;

	if (browse->option == TRUE)
		push_by_median_push(nb_top_pile, med.medianne_push, stack);
	else
	{
		set_quick(stack);
		do_inst('p', NO, stack);
	}
}

void get_medianne(t_stack stack)
{

	stack->med.mediane = get_med(stack->currrent_pile_dll,
								 stack->currrent_pile_dll->length);

	stack->med.medianne_push = get_median_push(stack->currrent_pile_dll,
											   &stack->browse,
											   stack->med.mediane,
											   FALSE);

	// faire des test pour voir si pertinent
	//	if (nb_med_push > 4)
	//	    ;
	//	if ((lim / 2) / 2 % 2 && lim > 6)
	//		browse->median_push--;

}

void
browse_pile_a(t_stack stack, size_t lim)
{
	size_t top_pile;
	t_dll_c pile;
	t_browse *browse;

	browse = &stack->browse;
	browse->lim = lim;
	get_medianne(stack);

	pile = stack->currrent_pile_dll;

	while (lim && pile->length > 3)
	{
		top_pile = dll_l_get_int(pile->top);
		if (top_pile < stack->med.mediane)
			browse_push(stack, top_pile);
		else
			do_inst('r', NO, stack);
		--lim;
	}
	browse->quick_count += 2;
}