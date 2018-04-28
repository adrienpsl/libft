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

#include "../../header/all_includes.h"

void dll_c_print_colorlst(t_dll_c lst, int a, int b)
{
	ssize_t i = lst->length;
	t_dll_l link = lst->top;

	if (lst->length == 0)
		return;

	ft_printf("\033[0m");
	while (i != -1)
	{
		if (dll_l_get_int(link) >= a && dll_l_get_int(link) <= b)
			ft_printf("\033[0;31m");
		else
			ft_printf("\033[0m");
		ft_printf("%2d ", dll_l_get_int(link));
		i--;
		if (i == 0)
		{
			ft_printf(" -- ");
			ft_printf("%d \n", lst->length);
			break;
		}
		link = link->next;
	}
	ft_printf("\033[0m");
	ft_printf(" \n");
}

void set_tet_tet(t_dll_c pile, int quick)
{
	t_dll_l link;
	size_t lim;

	lim = pile->length;
	link = pile->top;
	while (lim > 0)
	{
		((t_data) link->content)->quick = quick;
		link = link->next;
		lim--;
	}
}

void first_passage_a(t_stack stack)
{
	t_dll_c pile;

	pile = stack->pile_a;

	while (pile->length > 4)
	{
		set_stack('A', stack);
		browse_pile_a(stack, stack->currrent_pile_dll->length);

		////////////////////
		//		print_stack(stack);
		//		ft_printf("%d \n", stack->browse.option);
	}

	if (stack->pile_a->length == 3)
		sort_3_fuck_little(stack);
	else
		set_tet_tet(pile, stack->browse.quick_count + 1);
	// set quick sur toute la pile
	set_stack('A', stack);

	/////////////////////////////////////////////
//	print_stack(stack);
}

void test_2(t_stack stack)
{
	get_med_quick(stack);
	browser_inverse(stack, stack->med.mediane, stack->quick.counter_quick);
}

void test_2_rev(t_stack stack)
{
	get_med_quick_rev(stack);
	browser_reverse(stack, stack->med.mediane, stack->quick.counter_quick);
}

void brain_is_beauty(t_stack stack)
{
	t_quick *quick;
	static int p = 0;

	quick = &stack->quick;
	// get la ou il y a le plus grand

	update_quick(stack);
	while (quick->counter_quick > 4 && stack->pile_b->length)
	{
		p++;
		if (p == 15)
			1;
		quick->sens == 'T' ?
		test_2(stack)
						   :
		test_2_rev(stack);
		update_quick(stack);
		//		ft_printf("%d \n", p);
		//		print_stack(stack);
	}
	manage_all_short(stack);
}

// je ne verifie pas avec les petit si j'ai besoin de faire des trucs.
int main(int ac, char **av)
{
	t_argv argv;
	t_stack stack;

	argv = new_argv(ac, av);
	stack = get_stack_filled(argv);

	build_lst_a_index(stack->pile_a);

	if (stack->pile_a->length > 3)
	{
		first_passage_a(stack);
		while (stack->pile_b->length)
		{
			brain_is_beauty(stack);
		}
	}
	else
	{
		set_stack('A', stack);
		if (stack->pile_a->length <= 2)
			need_swap(stack);
		if (stack->pile_a->length == 3)
		{
			sort_3_fuck_little(stack);
		}
	}

	ft_printf("%s \n",stack->last_instruct);

//	print_stack(stack);
//	if (is_ordered(stack->pile_a, stack->pile_a->length))
//	{
//		ft_printf("yeah \n");
//	}
//	else
//		ft_printf("fuck \n");
	destroy_stack(&stack);
	destroy_argv(&argv);
	return (EXIT_SUCCESS);
}


//int rr_style(char *instr, t_stack stack)
//{
//	char *last;
//
//	last = stack->last_instruct;
//	if ((ft_strcmp(instr, "rrb") == FALSE &&
//		 ft_strcmp(last, "rra") == FALSE)
//		||
//		(ft_strcmp(instr, "rra") == FALSE &&
//		 ft_strcmp(last, "rrb") == FALSE)
//	 )
//	{
//		check_and_apply_instruct("rrr", stack);
//		return (TRUE);
//	}
//	return (FALSE);
//}
//
//int r_style(char *instr, t_stack stack)
//{
//	char *last;
//
//	last = stack->last_instruct;
//	if ((ft_strcmp(instr, "rb") == FALSE &&
//		 ft_strcmp(last, "ra") == FALSE)
//		||
//		(ft_strcmp(instr, "ra") == FALSE &&
//		 ft_strcmp(last, "rb") == FALSE)
//	 )
//	{
//		check_and_apply_instruct("rr", stack);
//		return (TRUE);
//	}
//	return (FALSE);
//}

//void do_instruct(char *instruc, t_stack stack)
//{
//
//	if (*stack->last_instruct)
//	{
//		if (r_style(instruc, stack) || rr_style(instruc, stack))
//			return ;
//		else
//			check_and_apply_instruct(stack->last_instruct, stack);
//		ft_memset(stack->last_instruct, 0, sizeof(char) * 4);
//		ft_strcpy(stack->last_instruct, instruc);
//	}
//	else
//		ft_strcpy(stack->last_instruct, instruc);
//
//}
