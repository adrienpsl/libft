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
#include <ft_str.h>

int lib_random_int(int limit)
{
	return (rand() % limit + 1);
}

void lib_print_func_int(void *ptr)
{
	printf("%3d ", *(int *)ptr);
}

void lib_clear_testbuff()
{
	ft_bzero(g_test_buffer, 10000);
}

int lib_cmp_testbuff_log(char *expected)
{
	int ret;
	int space;

	space = ft_strchr(g_test_buffer, ' ');
	ret = 0;
	if (ft_str_cmp(expected, g_test_buffer + space + 1))
	{
		ret = 1;
		printf("expected:%*s  %s", space, "", expected);
		printf("result  : %s\n", g_test_buffer);
	}
	lib_clear_testbuff();
	return (ret);
}

int lib_cmp_testbuff(char *expected)
{
	if (ft_str_cmp(expected, g_test_buffer))
	{
		printf("expected: %s\n", expected);
		printf("result  : %s\n", g_test_buffer);
		lib_clear_testbuff();
		return (1);
	}
	lib_clear_testbuff();
	return (0);
}

void
lib_print_func(void *start, void (*f)(void *), size_t size_el, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		f((char *)start + (i * size_el));
		i++;
	}
	printf(" \n");
}