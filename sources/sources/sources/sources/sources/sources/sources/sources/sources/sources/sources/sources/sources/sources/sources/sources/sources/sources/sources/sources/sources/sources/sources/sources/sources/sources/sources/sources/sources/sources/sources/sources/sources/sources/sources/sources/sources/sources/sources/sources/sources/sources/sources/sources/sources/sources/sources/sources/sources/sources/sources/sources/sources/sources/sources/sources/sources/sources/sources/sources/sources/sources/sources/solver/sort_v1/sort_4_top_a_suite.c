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

void aabb_sort4top_a(t_stack stack)
{
	need_swap(stack);
	if (is_ordered(stack->pile_a, 4))
		return;
	do_inst('r', NO, stack);
	do_inst('r', NO, stack);
	need_swap(stack);
	do_inst('a', NO, stack);
	do_inst('a', NO, stack);
}

void bbaa_sort4top_a(t_stack stack)
{
	do_inst('r', NO, stack);
	do_inst('r', NO, stack);
	do_inst('p', NO, stack);
	do_inst('p', NO, stack);
	do_inst('a', NO, stack);
	do_inst('a', NO, stack);
	need_swap(stack);
	do_inst('p', YES, stack);
	do_inst('p', YES, stack);
}



void sort_4_top_a(char *tab, t_stack stack)
{
	if (tab[0] == 'a' && tab[1] == 'a')
		aabb_sort4top_a(stack);
	else if (tab[0] == 'b' && tab[1] == 'b')
		bbaa_sort4top_a(stack);
	else if (ft_strcmp(tab, "abab") == FALSE)
		abab_sort4top_a(stack);
	else if (ft_strcmp(tab, "abba") == FALSE)
		abba_sort4top_a(stack);
	else if (ft_strcmp(tab, "baba") == FALSE)
		baba_sort4top_a(stack);
	else if (ft_strcmp(tab, "baab") == FALSE)
		baab_sort4top_a(stack);
}