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

static int is_argv(t_argv argv, char **str)
{
	*str = get_next_argv(argv);
	return (*str != NULL);
}

static int break_action_for_solver(int is_solver, char *cur_av, t_argv argv)
{
	if (is_solver == ACTIVATE)
	{
		if (is_action(cur_av))
		{
			argv_go_prev_argv(argv);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_dll_c get_list_a(t_argv argv, int is_solver)
{
	t_dll_c c_list;
	t_dll_l link;
	t_data data;

	char *cur_av;

	c_list = new_dll_c();
	while (is_argv(argv, &cur_av) == TRUE)
	{
		if (break_action_for_solver(is_solver, cur_av, argv) == TRUE)
			break;
		data = malloc(sizeof(struct s_data));
		ft_memset(data, 0, sizeof(struct s_data));
		data->nb = is_valide_number(cur_av, c_list);

		link = new_dll_l(data, sizeof(struct s_data));
		dll_c_add_after(link, c_list);
		free(data);
	}
	return (c_list);
}