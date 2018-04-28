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

#include "../../ft_library_header.h"

static void swap(int tab[], int a, int b)
{
	int temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

void ft_quick_sort(int *tab, int start, int end)
{
	int left;
	int right;
	int pivot;

	if (start >= end)
		return;
	pivot = tab[start];
	left = start;
	right = end;
	while (1)
	{
		while (tab[left] < pivot)
		{
			left++;
		}
		while (tab[right] > pivot)
		{
			right--;
		}
		if (tab[left] > tab[right])
			swap(tab, left, right);
		else
			break;
	}
	ft_quick_sort(tab, start, right);
	ft_quick_sort(tab, right + 1, end);
}

