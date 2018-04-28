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

// je dois calculer les medianne push en quick


void get_med_quick(t_stack stack)
{
	t_dll_c med_quick_list;

	med_quick_list = new_dll_c();

	med_quick_list->top = stack->currrent_pile_dll->top;
	med_quick_list->length = stack->quick.counter_quick;

	stack->med.mediane = get_med(med_quick_list,
								 med_quick_list->length);
	if (med_quick_list->length)
	{
		stack->browse.lim = stack->quick.counter_quick;

//		dll_c_print_lst(med_quick_list);
		stack->med.medianne_push = get_median_push(med_quick_list,
												   &stack->browse,
												   stack->med.mediane,
												   stack->current_pile == 'A' ?
												   FALSE : TRUE);
	}
	free(med_quick_list);
}

void get_med_quick_rev(t_stack stack)
{
	t_dll_c pile;
	int i;

	pile = new_dll_c();
	pile->top = stack->currrent_pile_dll->top;
	pile->length = stack->quick.counter_quick;;

	i = stack->quick.counter_quick;
	while (i)
	{
		pile->top = pile->top->prev;
		--i;
	}

	stack->med.mediane = get_med(pile,
								 stack->quick.counter_quick);
//	dll_c_print_lst(pile);
	stack->browse.lim = stack->quick.counter_quick;
	stack->med.medianne_push = get_median_push(pile, &stack->browse,
											   stack->med.mediane, TRUE);
	free(pile);
}