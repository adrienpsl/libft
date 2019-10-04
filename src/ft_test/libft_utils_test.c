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

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ft_mem.h>
#include <ft_test.h>
#include <ft_str.h>

int					test_random_int(int limit)
{
	return (rand() % limit + 1);
}

void	test_print_func_int(void *ptr)
{
	printf("%3d ", *(int *)ptr);
}

void	test_clear_testbuff()
{
	ft_bzero(g_test_buffer, 10000);
}

int					test_cmp_testbuff_log(char *expected)
{
	int ret;
	int space;

	space = ft_strchr_int(g_test_buffer, ' ');
	ret = 0;
	if (ft_strcmp(expected, g_test_buffer + space + 1))
	{
		ret = 1;
		printf("expected:%*s  %s", space, "", expected);
		printf("result  : %s\n", g_test_buffer);
	}
	test_clear_testbuff();
	return (ret);
}

int					test_cmp_buff(char *expected)
{
	if (ft_strcmp(expected, g_test_buffer))
	{
		printf("expected: %s\n", expected);
		printf("result  : %s\n", g_test_buffer);
		test_clear_testbuff();
		return (1);
	}
	test_clear_testbuff();
	return (0);
}

int					test_cmp_str(char *result, char *ret)
{
	if (
		result == NULL && ret == NULL
		)
		return (0);
	if (
		OK != ft_strcmp(result, ret)
		)
	{
		printf("test cmp str\n");
		printf("expected : %s\n", result);
		printf("return   : %s\n", ret);
		return (1);
	}
	return (0);
}

void
test_print_func(void *start, void (*f)(void *), size_t size_el, int length);
void
test_print_func(void *start, void (*f)(void *), size_t size_el, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		f((char *)start + ((size_t)i * size_el));
		i++;
	}
	printf(" \n");
}

int					test_cmp_split_str(char *name, char *expected, char **returned)
{
	g_test = 1;
	test_clear_testbuff();
	if (expected == NULL && returned == NULL)
		return (0);

	if (expected == NULL || returned == NULL)
	{
		printf("%s\nptr null : %p %p", name, expected, returned);
		return (1);
	}
	ft_strsplit_print(returned, ' ');

	if (test_cmp_buff(expected))
	{
		printf("%s", name);
		return (1);
	}
	g_test = 0;
	return (0);
}

int					test_cmp_int(int expected, int returned)
{
	if (expected != returned)
	{
		printf("error return : \n");
		printf("expected : %d \n", expected);
		printf("returned : %d \n", returned);
		return (1);
	}
	return (0);
}