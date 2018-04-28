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

static void set_index(t_dll_c pile_1, size_t size)
{
	t_dll_l link_p1;
	t_dll_l link_p2;
	t_dll_c pile_2;
	int a;

	pile_2 = new_dll_c();
	dll_c_copie(pile_1, pile_2, size);
	build_lst_a_index(pile_2);
	link_p1 = pile_1->top;
	link_p2 = pile_2->top;

	while (size > 0)
	{
		a = dll_l_get_int(link_p2);
		((t_data) link_p1->content)->n = a == 0 || a == 1 ? 'a' : 'b';
		((t_data) link_p1->content)->short_ = a;
		link_p1 = link_p1->next;
		link_p2 = link_p2->next;
		size--;
	}
	destroy_dll_c(&pile_2);
}

void static set_tab_ab(t_dll_c pile, char tab[])
{
	tab[0] = ((t_data) pile->top->content)->n;
	tab[1] = ((t_data) pile->top->next->content)->n;
	tab[2] = ((t_data) pile->top->next->next->content)->n;
	tab[3] = ((t_data) pile->top->next->next->next->content)->n;
}

void sort_4(t_stack stack)
{
	t_dll_c pile;
	char tab[5];

	ft_memset(tab, 0, sizeof(char) * 5);
	pile = stack->current_pile == 'A' ? stack->pile_a : stack->pile_b;
	set_index(pile, 4);
	set_tab_ab(pile, tab);
	if (stack->current_pile == 'A')
		sort_4_top_a(tab, stack);
	else
		sort_4_top_b(tab, stack);
}