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

void check_and_apply_instruct(char *str, t_stack stack)
{
	if (ft_strcmp("sa", str) == FALSE)
		sa(stack);
	else if (ft_strcmp("sb", str) == FALSE)
		sb(stack);
	else if (ft_strcmp("ss", str) == FALSE)
		ss(stack);
	else if (ft_strcmp("pa", str) == FALSE)
		pa(stack);
	else if (ft_strcmp("pb", str) == FALSE)
		pb(stack);
	else if (ft_strcmp("ra", str) == FALSE)
		ra(stack);
	else if (ft_strcmp("rb", str) == FALSE)
		rb(stack);
	else if (ft_strcmp("rr", str) == FALSE)
		rr(stack);
	else if (ft_strcmp("rra", str) == FALSE)
		rra(stack);
	else if (ft_strcmp("rrb", str) == FALSE)
		rrb(stack);
	else if (ft_strcmp("rrr", str) == FALSE)
		rrr(stack);
	else
		exit_wrong_nb();
}
