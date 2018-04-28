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

#include "../header/all_includes.h"

void set_index_ab(t_dll_c pile_1, size_t size)
{
	t_dll_l link_p1;
	t_dll_l link_p2;
	t_dll_c pile_2;
	int a;

	pile_2 = new_dll_c();
	dll_c_copie(pile_2, pile_1, size);
	build_lst_a_index(pile_2);
	link_p1 = pile_1->top;
	link_p2 = pile_2->top;

	while (size > 0)
	{
		a = dll_l_get_int(link_p2);
		((t_data) link_p1->content)->n = a == 0 ? 'a' : 'b';
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
}

void sort_3_fuck_little(t_stack stack)
{
	t_dll_c pile;
	char tab[4];

	ft_memset(tab, 0, sizeof(char) * 4);
	pile = stack->currrent_pile_dll;
	set_index_ab(pile, 3);
	set_tab_ab(pile, tab);
	if (ft_strcmp(tab, "abb") == FALSE)
	{
		do_instruct("ra",stack);
		need_swap(stack);
		do_instruct("rra",stack);
	}
	else if (ft_strcmp(tab, "bab") == FALSE)
	{
		do_instruct("rra",stack);
		need_swap(stack);
		do_instruct("rra",stack);
	}
	else if (ft_strcmp(tab, "bba") == FALSE)
	{
		need_swap(stack);
		do_instruct("rra",stack);
	}
}