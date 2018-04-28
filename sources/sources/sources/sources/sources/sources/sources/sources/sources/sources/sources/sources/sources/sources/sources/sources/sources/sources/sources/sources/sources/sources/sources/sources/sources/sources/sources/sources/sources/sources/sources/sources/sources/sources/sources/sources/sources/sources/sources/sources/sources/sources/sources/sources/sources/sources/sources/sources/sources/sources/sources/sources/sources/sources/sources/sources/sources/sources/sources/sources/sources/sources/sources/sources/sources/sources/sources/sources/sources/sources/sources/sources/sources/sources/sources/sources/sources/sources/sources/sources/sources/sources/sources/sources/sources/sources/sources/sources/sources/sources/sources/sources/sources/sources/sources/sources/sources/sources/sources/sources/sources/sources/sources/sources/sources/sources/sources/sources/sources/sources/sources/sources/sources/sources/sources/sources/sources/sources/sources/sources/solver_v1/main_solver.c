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
//size_t need_pb(t_stack stack)
//{
//	size_t nb_top;
//
//	nb_top = dll_l_get_int(stack->pile_a->top);
//	return (nb_top < stack->mediane_up && nb_top >= stack->mediane_down);
//}
//
//size_t is_4(t_stack stack)
//{
//	size_t nb_top;
//
//	nb_top = dll_l_get_int(stack->pile_a->top);
//	return (nb_top % 4 == FALSE);
//}
//
//size_t is_already_sorted(t_stack stack)
//{
//	size_t nb_top;
//
//	nb_top = dll_l_get_int(stack->pile_a->top);
//	return (nb_top < stack->mediane_down);
//}
//
///*
//**    deroule liste_a, si top list_a est inclu dans median, je l'envoie dans b
//*/
//void get_first_pasage(t_stack stack)
//{
//	size_t i;
//	size_t temp;
//
//	temp = stack->pile_a->length;
//	i = 0;
//	while (i < temp)
//	{
//		if (need_pb(stack))
////		if (is_4(stack))
//			push_in_b(stack);
////					do_instruct("pb", stack);
//
//		else
//		{
//			do_instruct("ra", stack);
//			i++;
//			continue;
//		}
//		print_stack(stack);
//		if (stack->pile_b->length > stack->median_junp)
//			break;
//		//		if (is_already_sorted(stack))
//		//			break;
//		i++;
//	}
//}
//
//
//void get_first_pasage2(t_stack stack, int test)
//{
//	size_t i;
//	size_t temp;
//
//	temp = stack->pile_b->length;
//	i = 0;
//	while (i < temp)
//	{
//		if ( dll_l_get_int(stack->pile_b->top) > test)
//						push_in_b(stack);
////			do_instruct("pa", stack);
//
//		else
//		{
//			do_instruct("rb", stack);
//			i++;
//			continue;
//		}
//		print_stack(stack);
//		if (stack->pile_b->length > stack->median_junp)
//			break;
//		//		if (is_already_sorted(stack))
//		//			break;
//		i++;
//	}
//}
//
//
//void repush_b(t_stack stack)
//{
//	while (stack->pile_b->length != 0)
//	{
//		do_instruct("pa", stack);
//		stack->nb_already_sorted += 1;
//	}
//}
//
//void
//set_good_beguin(int researched_nb, t_dll_l top_link, int pile, t_stack stack)
//{
//	int opt;
//
//	opt = find_up_down(NULL, researched_nb, top_link, stack);
//	if (pile == LIST_A)
//		do_the_ops_pilea(stack, opt);
//	else if (pile == LIST_B)
//		do_the_ops_pileb(stack, opt);
//}
//
//void first_p(t_stack stack, int med)
//{
//	dll_c_print_lst(stack->pile_a);
//
//	get_median(stack, med, FALSE);
//	get_first_pasage(stack);
//
//	// il ya une optimisation a faire ici
//	set_good_beguin(stack->max_lim, stack->pile_b->top, LIST_B, stack);
//	repush_b(stack);
//
////	get_first_pasage2(stack, 25);
////	get_first_pasage2(stack, 12);
////	get_first_pasage2(stack, 6);
////	get_first_pasage2(stack, 3);
////	get_first_pasage2(stack, 1);
////	repush_b(stack);
////	get_median(stack, med, FALSE);
////
////	get_first_pasage(stack);
////	get_first_pasage2(stack, 75);
////	get_first_pasage2(stack, 62);
////	get_first_pasage2(stack, 56);
////	get_first_pasage2(stack, 53);
////	repush_b(stack);
//
//	print_stack(stack);
//};
//
//
//
//
//void one_tour(t_stack stack, int med, int is_the_last)
//{
//	get_median(stack, med, is_the_last);
//
//	get_first_pasage(stack);
//
//	// good beguin lst_b
//	set_good_beguin(stack->max_lim, stack->pile_b->top, LIST_B, stack);
//	//	print_stack(stack);
//
//	// good beguin lst_a
//	set_good_beguin(0, stack->pile_a->top, LIST_A, stack);
//	//	print_stack(stack);
//
//	repush_b(stack);
//}
//
//// quand je remet b au bon endoit, il faut que je regarde si je peux faire rra ou rr en meme temps
////int main(int ac, char **av)
////{
////	t_argv argv;
////	t_stack stack;
////
////	int med = 3;
////
////	argv = new_argv(ac, av);
////	stack = get_stack_filled(argv);
////	build_lst_a_index(stack->pile_a);
////
////
////	// premier pasage
////	first_p(stack, med);
////
////	int tour = 2;
////	while (med != 2)
////	{
////		printf(
////		 "-------- tour : %d  ------------------------------------------------------------------------------------\n"
////		 "-----------------------------------------------------------------------------------------------------------------------------------------------------\n"
////		 "--------------------------------------------------------------------------------------------------------\n"
////		 "%d", tour, stack->count);
////		one_tour(stack, med, FALSE);
////		med -= 1;
////		tour++;
////	}
////
////	one_tour(stack, med, TRUE);
////	//
////	set_good_beguin(0, stack->pile_a->top, LIST_A, stack);
////	//
////		print_stack(stack);
////
////	printf("\n%d \n", stack->count);
////	return (EXIT_SUCCESS);
////}
