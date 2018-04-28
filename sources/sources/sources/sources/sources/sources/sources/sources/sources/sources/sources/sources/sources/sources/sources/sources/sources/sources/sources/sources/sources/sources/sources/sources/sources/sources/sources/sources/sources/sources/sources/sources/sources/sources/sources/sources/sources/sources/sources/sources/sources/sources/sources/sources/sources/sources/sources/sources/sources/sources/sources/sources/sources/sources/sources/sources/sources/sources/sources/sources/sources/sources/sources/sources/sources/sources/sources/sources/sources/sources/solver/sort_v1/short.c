///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_atoi.c                                          :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
///*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../../header/all_includes.h"
//
//void a_2_b_2(t_stack stack)
//{
//	int median;
//
//	median = get_med(stack->pile_a, stack->pile_a->length);
//
//	//	browse_pile_a(stack, median, stack->pile_a->length, FALSE);
//
//	need_swap(stack);
//
//	do_instruct("pa", stack);
//	do_instruct("pa", stack);
//}
//
//void two_end_b(t_stack stack)
//{
//	do_instruct("rrb", stack);
//	do_instruct("rrb", stack);
//	need_swap(stack);
//	do_instruct("pa", stack);
//	do_instruct("pa", stack);
//}
//
//void b_2_2(t_stack stack)
//{
//	do_instruct("pa", stack);
//	do_instruct("pa", stack);
//	two_end_b(stack);
//}
//
//void nb_pile_b_last(t_stack stack)
//{
//
//	int median;
//
//	median = get_med(stack->pile_b, 4);
//
//	//	browse_pile_b(stack, median, 4, FALSE);
//	print_stack(stack);
//	need_swap(stack);
//	do_instruct("pa", stack);
//	do_instruct("pa", stack);
//}
//
//void b_4(t_stack stack)
//{
//	int median;
//
//	median = get_med(stack->pile_b, 4);
//	ft_printf("%d \n", median);
//
//	set_brower(median, 4, FALSE, stack);
//	stack->browse.pile = PILE_B;
//	browse_pile(stack, &stack->browse);
//
//	do_instruct("rrb", stack);
//	do_instruct("rrb", stack);
//	need_swap(stack);
//	do_instruct("pa", stack);
//	do_instruct("pa", stack);
//}
//
//void print_short_list(t_dll_c lst)
//{
//	ssize_t i = lst->length;
//	t_dll_l link = lst->top;
//
//	if (lst->length == 0)
//		return;
//	while (i != -1)
//	{
//		ft_printf("%2d ", ((t_data) link->content)->short_);
//		i--;
//		if (i == 0)
//			break;
//		link = link->next;
//	}
//	ft_printf(" \n");
//}
//
//int get_short_(t_dll_l link)
//{
//	return (((t_data) link->content)->short_);
//}
//
//
//
////void is_abab(t_dll_c pile, t_stack stack)
////{
////	int a;
////	int b;
////	int c;
////
////	(void) stack;
////	a = get_short_(pile->top);
////	b = get_short_(pile->top->next);
////	c = get_short_(pile->top->next->next);
////	if ((((a == 0 || a == 1) && (b == 2 || b == 3)) && (c == 0 || c == 1)) ||
////		(((a == 2 || a == 3) && (b == 0 || b == 1)) && (c == 2 || c == 3)))
////	{
////		do_instruct(stack->browse.pile == PILE_A ? "sa" : "sb", stack);
////		do_instruct(stack->browse.pile == PILE_A ? "rra" : "rrb", stack);
////		need_swap(stack);
////	}
////}
//
////int is_bigest_start(t_dll_c pile, t_stack stack)
////{
////	int a;
////	int b;
////	int c;
////	t_browse browse;
////
////	browse = stack->browse;
////	a = get_short_(pile->top);
////	b = get_short_(pile->top->next);
////	c = get_short_(pile->top->next->next->next);
////
////	ft_printf("%d %d\n", stack->browse.pile, PILE_A);
////	if ((a == 0 || a == 1) && (c == 0 || c == 1))
////		do_instruct(stack->browse.pile == PILE_A ? "ra" : "rb", stack);
////	else if ((a == 2 || a == 3) && (c == 2 || c == 3))
////		do_instruct(stack->browse.pile == PILE_A ? "rra" : "rrb", stack);
////
////	a = get_short_(pile->top);
////	b = get_short_(pile->top->next);
////	print_stack(stack);
////	if (a == 2 || a == 3)
////	{
////		need_swap(stack);
////		do_instruct(stack->browse.pile == PILE_A ? "ra" : "rb", stack);
////		do_instruct(stack->browse.pile == PILE_A ? "ra" : "rb", stack);
////		need_swap(stack);
////		return (TRUE);
////	}
////	return (FALSE);
////}
////
////int is_lowest_start(t_dll_c pile, t_stack stack)
////{
////	int a;
////	int b;
////	t_browse browse;
////
////	browse = stack->browse;
////	a = get_short_(pile->top);
////	b = get_short_(pile->top->next);
////	if (a == 0 || a == 1)
////	{
////		need_swap(stack);
////		do_instruct(stack->browse.pile == PILE_A ? "ra" : "rb", stack);
////		do_instruct(stack->browse.pile == PILE_A ? "ra" : "rb", stack);
////		need_swap(stack);
////		do_instruct(stack->browse.pile == PILE_A ? "ra" : "rb", stack);
////		do_instruct(stack->browse.pile == PILE_A ? "ra" : "rb", stack);
////	}
////	return (TRUE);
////}
//
////void a_4(t_stack stack)
////{
////	//	int median;
////	t_dll_c pile;
////
////	pile = stack->pile_a;
////	set_index_sort_algo(pile);
////
////	is_abab(pile, stack);
////	(is_bigest_start(pile, stack) || is_lowest_start(pile, stack));
////}
//
//void b_3(t_stack stack)
//{
//	//	int a;
//	//	int b;
//	//	t_dll_c pile_a;
//	//	t_dll_c pile_b;
//
//	//	do_instruct("pa", stack);
//	//	do_instruct("pa", stack);
//	need_swap(stack);
//	//	if ()
//
//}
//
//
//
//