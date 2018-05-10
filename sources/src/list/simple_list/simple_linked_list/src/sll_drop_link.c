/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_drop_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:49:15 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

static int		one_el(t_sll_l link, t_sll list)
{
	if (link != list->top)
		return (FALSE);
	else
	{
		list->top = NULL;
		list->tail = NULL;
		return (TRUE);
	}
}

static int		two_el(t_sll_l link, t_sll list)
{
	if (link == list->top)
	{
		list->top = link->next;
		link->next = NULL;
		return (TRUE);
	}
	if (link == list->tail)
	{
		list->tail = list->top;
		list->tail->next = NULL;
		return (TRUE);
	}
	return (FALSE);
}

static int		more_el(t_sll_l link, t_sll list)
{
	t_sll_l prev;

	prev = list->top;
	while (prev && prev->next != link)
	{
		prev = prev->next;
	}
	if (prev && prev->next == link)
	{
		prev->next = link->next;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_sll_l			sll_drop_link(t_sll_l link, t_sll list)
{
	int find;

	find = FALSE;
	if (list->lenght == 0)
		return (NULL);
	else if (list->lenght == 1)
		find = one_el(link, list);
	else if (list->lenght == 2)
		find = two_el(link, list);
	else
		find = more_el(link, list);
	if (find != FALSE)
		list->lenght -= 1;
	return (find != FALSE ? link : NULL);
}
