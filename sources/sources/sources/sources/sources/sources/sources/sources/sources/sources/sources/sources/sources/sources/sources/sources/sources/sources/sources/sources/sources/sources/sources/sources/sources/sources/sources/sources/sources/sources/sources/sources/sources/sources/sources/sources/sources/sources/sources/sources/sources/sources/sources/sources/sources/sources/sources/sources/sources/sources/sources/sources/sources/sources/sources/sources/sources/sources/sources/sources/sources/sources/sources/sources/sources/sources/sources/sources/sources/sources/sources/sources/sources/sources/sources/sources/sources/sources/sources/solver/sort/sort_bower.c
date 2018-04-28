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

void sort_browser(t_stack stack, size_t med, size_t lim)
{
	size_t top_pile;
	t_dll_c pile;

	pile = stack->currrent_pile_dll;
	while (lim > 0)
	{
		top_pile = dll_l_get_int(pile->top);
		if ((stack->current_pile == 'A' && top_pile < med) ||
			(stack->current_pile == 'B' && top_pile >= med))
			do_inst('p', NO, stack);
		else
			do_inst('r', NO, stack);
		--lim;
	}
}

void sort_browser_reverse(t_stack stack, size_t med, size_t lim)
{
	size_t top_pile;
	t_dll_c pile;

	pile = stack->currrent_pile_dll;
	while (lim > 0)
	{
		do_inst('a', NO, stack);
		top_pile = dll_l_get_int(pile->top);
		if ((stack->current_pile == 'A' && top_pile < med) ||
			(stack->current_pile == 'B' && top_pile >= med))
			do_inst('p', NO, stack);
		--lim;
	}
}