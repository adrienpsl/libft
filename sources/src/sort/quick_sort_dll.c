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
//#include "../../ft_library_header.h"
//
//int ddl_is_top(t_dll list, t_dll_l link){
//	return (link == list->top);
//}
//
//int ddl_is_end(t_dll list, t_dll_l link){
//	return (link == list->end);
//}
//
//int dll_l_is_bigger(t_dll_l a, t_dll_l b)
//{
//	return (dll_l_get_int(a) > dll_l_get_int(b));
//}
//
///*
//**    is lower or equal
//*/
//int dll_l_is_loweq(t_dll_l a, t_dll_l b)
//{
//	return (dll_l_get_int(a) <= dll_l_get_int(b));
//}
//
//static void swap(t_dll_l a, t_dll_l b)
//{
//	int temp;
//
//	temp = dll_l_get_int(a);
//	*(int *) a->content = *(int *) b->content;
//	*(int *) b->content = temp;
//}
//
//void ft_quick_sort_dll(t_dll list, t_dll_l start, t_dll_l end /* ,t_dll_l last*/)
//{
//	t_dll_l left;
//	t_dll_l right;
//	t_dll_l pivot;
//
//	if (start == end)
//		return;
//	pivot = start;
//	left = start->prev == NULL ? start : start->prev;
//	right = end->next == NULL ? end : end->prev;
////	while (1)
////	{
////		while (tab[right] > pivot)
////		{
////			right--;
////		}
////		while (tab[left] < pivot)
////		{
////			left++;
////		}
////		if (left < right)
////			swap(tab, left, right);
////		else
////			break;
////	}
////	ft_quick_sort(tab, start, right, last);
////	ft_quick_sort(tab, right + 1, end, last);
////}