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

#include <printf.h>
#include "../../ft_library_header.h"

static void		swap(int tab[], int a, int b)
{
	int temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

void			ft_quick_sort(int *tab, int start, int end, int last)
{
	int left;
	int right;
	int pivot;


	pivot = tab[start];
	left = (start - 1) < 0 ? start : start - 1;
	right = end + 1 > last ? last : end + 1;
	if (start >= end)
		return ;
	while (1)
	{
		while (tab[right] > pivot)
			right--;
		while (tab[left] < pivot)
			left++;
		if (left < right)
			swap(tab, left, right);
		else
			break ;
	}
	ft_quick_sort(tab, start, right, last);
	ft_quick_sort(tab, right + 1, end, last);
}
