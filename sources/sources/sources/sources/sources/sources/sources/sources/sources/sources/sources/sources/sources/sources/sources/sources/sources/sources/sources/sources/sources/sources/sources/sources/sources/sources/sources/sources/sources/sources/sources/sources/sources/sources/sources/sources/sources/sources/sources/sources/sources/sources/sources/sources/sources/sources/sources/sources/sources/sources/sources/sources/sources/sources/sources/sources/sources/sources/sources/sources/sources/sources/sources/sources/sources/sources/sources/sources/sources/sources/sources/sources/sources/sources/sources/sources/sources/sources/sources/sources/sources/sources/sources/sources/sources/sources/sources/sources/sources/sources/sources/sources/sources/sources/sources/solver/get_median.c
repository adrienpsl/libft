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

t_dll_c get_list_med_push(t_dll_c origin, int med, int op)
{
	t_dll_c pile_push_med;
	t_dll_l origin_link;
	t_dll_l copied_link;
	size_t size;

	pile_push_med = new_dll_c();
	origin_link = origin->top;
	size = origin->length;
	while (size)
	{
		if ((op == FALSE && dll_l_get_int(origin_link) <= med) ||
			(op == TRUE && dll_l_get_int(origin_link) >= med))
		{
			copied_link = new_dll_l(origin_link->content, sizeof(int));
			dll_c_push_link(copied_link, pile_push_med);
		}
		size--;
		origin_link = origin_link->next;
	}
	return (pile_push_med);
}

int get_median_push(t_dll_c origin, t_browse *browse, int med, int op)
{
	int med_push;

	t_dll_c pile_push_med;

	if (browse->lim / 2 < 6)
	{
		browse->option = FALSE;
		return 0;
	}
	browse->option = TRUE;
	pile_push_med = get_list_med_push(origin, med, op);

//	dll_c_print_lst(pile_push_med);

	med_push = get_med(pile_push_med,
					   pile_push_med->length);
	destroy_dll_c(&pile_push_med);

	return (med_push);
}

int get_med(t_dll_c c_list, int length)
{
	int a;
	int *tab;

	tab = get_fill_tab(c_list, length);
	ft_quick_sort(tab, 0, length - 1);

	a = tab[length / 2];
	free(tab);
	return (a);
}