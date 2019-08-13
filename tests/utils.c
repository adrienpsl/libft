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

#include <stdlib.h>
#include <stdio.h>
#include <ft_mem.h>
#include <libft.test.h>

int lib_random_int(int limit)
{
	return (rand() % limit + 1);
}

void lib_print_func_int(void *ptr)
{
	printf("%3d ", *(int *) ptr);
}

void lib_clear_testbuff()
{
	ft_bzero(g_test_buffer, 10000);
}

void
lib_print_func(void *start, void (*f)(void *), size_t size_el, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		f((char *) start + (i * size_el));
		i++;
	}
	printf(" \n");
}