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

int rr_style(char *instr, t_stack stack)
{
	char *last;

	last = stack->last_instruct;
	if ((ft_strcmp(instr, "rrb") == FALSE &&
		 ft_strcmp(last, "rra") == FALSE)
		||
		(ft_strcmp(instr, "rra") == FALSE &&
		 ft_strcmp(last, "rrb") == FALSE)
	 )
	{
		ft_printf("rrr");
		return (TRUE);
	}
	return (FALSE);
}

int r_style(char *instr, t_stack stack)
{
	char *last;

	last = stack->last_instruct;
	if ((ft_strcmp(instr, "rb") == FALSE &&
		 ft_strcmp(last, "ra") == FALSE)
		||
		(ft_strcmp(instr, "ra") == FALSE &&
		 ft_strcmp(last, "rb") == FALSE)
	 )
	{
		ft_printf("rr");
		return (TRUE);
	}
	return (FALSE);
}


void do_instruct(char *instruc, t_stack stack)
{

	check_and_apply_instruct(instruc, stack);
//	ft_printf("%s ",instruc);

	if (*stack->last_instruct)
	{
		if (r_style(instruc, stack) || rr_style(instruc, stack))
		{
			ft_memset(stack->last_instruct, 0, sizeof(char) * 4);
			ft_printf("\n");
			stack->count++;
			return;
		}
		else
			ft_printf("%s\n",stack->last_instruct);
		stack->count++;
		ft_memset(stack->last_instruct, 0, sizeof(char) * 4);
		ft_strcpy(stack->last_instruct, instruc);
	}
	else
		ft_strcpy(stack->last_instruct, instruc);
}

static void pile_a(char instruction, int op, char tab_ins[])
{
	tab_ins[0] = instruction;

	if (instruction == 'p')
		tab_ins[1] = op == NO ? 'b' : 'a';
	else if (instruction == 'a')
	{
		tab_ins[0] = 'r';
		tab_ins[1] = 'r';
		tab_ins[2] = op == NO ? 'a' : 'b';
	}
	else
		tab_ins[1] = op == NO ? 'a' : 'b';
}

static void pile_b(char instruction, int op, char tab_ins[])
{
	tab_ins[0] = instruction;

	if (instruction == 'p')
		tab_ins[1] = op == NO ? 'a' : 'b';
	else if (instruction == 'a')
	{
		tab_ins[0] = 'r';
		tab_ins[1] = 'r';
		tab_ins[2] = op == NO ? 'b' : 'a';
	}
	else
		tab_ins[1] = op == NO ? 'b' : 'a';
}

void do_inst(char raw_instruction, int option, t_stack stack)
{
	char instruction[4];

	ft_memset(instruction, 0, sizeof(char) * 4);
	stack->current_pile == 'A' ?
	pile_a(raw_instruction, option, instruction) :
	pile_b(raw_instruction, option, instruction);
	do_instruct(instruction, stack);
}
void do_the_ops_pileb(t_stack stack, long nb_operations)
{
	while (nb_operations > 0)
	{
		do_instruct("rb", stack);
		nb_operations--;
	}
	while (nb_operations < 0)
	{
		do_instruct("rrb", stack);
		nb_operations++;
	}
}

void do_the_ops_pilea(t_stack stack, long nb_operations)
{
	while (nb_operations > 0)
	{
		do_instruct("ra", stack);
		nb_operations--;
	}
	while (nb_operations < 0)
	{
		do_instruct("rra", stack);
		nb_operations++;
	}
}