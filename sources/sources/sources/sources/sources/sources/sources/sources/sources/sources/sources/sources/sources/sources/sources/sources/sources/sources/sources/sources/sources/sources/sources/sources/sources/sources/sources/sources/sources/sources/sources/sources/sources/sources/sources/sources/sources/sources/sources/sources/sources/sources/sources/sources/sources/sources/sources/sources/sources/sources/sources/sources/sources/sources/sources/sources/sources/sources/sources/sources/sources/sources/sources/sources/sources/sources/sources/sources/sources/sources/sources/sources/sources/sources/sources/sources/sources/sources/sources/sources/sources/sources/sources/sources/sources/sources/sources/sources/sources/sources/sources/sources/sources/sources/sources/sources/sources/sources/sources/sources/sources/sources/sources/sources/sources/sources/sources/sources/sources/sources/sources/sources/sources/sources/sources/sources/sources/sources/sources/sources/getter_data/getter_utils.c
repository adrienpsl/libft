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

void exit_wrong_nb()
{
	ft_putstr_fd("Error",2);
	exit(42);
}

int is_action(char *str)
{
	static char instruct[11][3] = {
	 "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
	};
	int i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(instruct[i], str) == FALSE)
			return (TRUE);
		++i;
	}
	return (FALSE);
}