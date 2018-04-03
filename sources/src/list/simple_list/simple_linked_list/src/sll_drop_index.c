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
//#include "../../../../../ft_library_header.h"
//
//static t_sll_l one_el(t_sll list)
//{
//	list->top = NULL;
//	return (link);
//}
//
//static t_sll_l top_or_head(size_t index, t_sll list)
//{
//	t_sll_l link;
//
//	if (index == 0)
//	{
//		link = list->top;
//		list->top = list->top->next;
//		link->next = NULL;
//		return (link);
//	}
//	if (index >= list->lenght)
//	{
//		link = list->top;
//		list->top->next = NULL;
//		list->tail = list->top;
//		return (link);
//	}
//	return (NULL);
//}
//
//static t_sll_l more_el(t_sll_l link, t_sll list)
//{
//	t_sll_l prev;
//
//	prev = list->top;
//	while (prev && prev->next != link)
//	{
//		prev = prev->next;
//	}
//	if (prev && prev->next == link)
//	{
//		prev->next = link->next;
//		return (link);
//	}
//	else
//		return (NULL);
//}
//
//static int link_is_top_tail(t_sll_l link, t_sll list)
//{
//	return (link == list->top || link == list->tail);
//}
//
//t_sll_l sll_drop_index(t_sll_l link, t_sll list)
//{
//	t_sll_l out_link;
//
//	out_link = NULL;
//	if (list->lenght == 0)
//		return (NULL);
//	else if (list->lenght == 1)
//		out_link = one_el(link, list);
//	else if (list->lenght == 2 || link_is_top_tail(link, list))
//		out_link = two_el(link, list);
//	else
//		out_link = more_el(link, list);
//	if (out_link != NULL)
//		list->lenght -= 1;
//	return (out_link);
//}