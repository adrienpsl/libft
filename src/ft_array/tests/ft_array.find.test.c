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

# include "libft.h"
# include "ft_array.test.h"

static int			find_func(void *el, void *searched)
{
	int *nb;
	int *wanted;

	nb = el;
	wanted = searched;
	return (*nb == *wanted);
}

void	test_ftarray__find(void)
{
	/*
	* test error handling
	* */
	{
		int ret;
		g_test = 1;

		// test no array
		{
			test_clear_testbuff();

			ret = ftarray__find(NULL, ftarray__func_print_int, NULL);
			if (
				ret != -1
				|| test_cmp_testbuff_log(
					"ftarray__find error: array ptr (null)\n")
				)
				log_test(0)

			t_array *ptr = (t_array *)0x123;
			ret = ftarray__find(ptr, NULL, NULL);
			if (
				ret != -1
				||
				test_cmp_testbuff_log(
					"ftarray__find error: func ptr (null)\n")
				)
				log_test(1)
		}
		g_test = 0;
	}

	/*
	* test all good
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		int ret;
		int searched;
		t_array *array;

		// test 1 element
		{
			searched = 1;
			array = ftarray__init_data(data, 1, sizeof(int));
			ret = ftarray__find(array, find_func, &searched);

			if (
				ret != -1
				)
				log_test(2)
			ftarray__free(&array);
		}

		// test two elements
		{
			searched = 10;
			array = ftarray__init_data(data, 2, sizeof(int));

			ret = ftarray__find(array, find_func, &searched);

			if (
				ret != 1
				)
				log_test(3)
			ftarray__free(&array);
		}

		// test 10 elements
		{
			int test[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			array = ftarray__init_data(test, 10, sizeof(int));

			for (int i = 0; i < 10; ++i)
			{
				searched = i;
				ret = ftarray__find(array, find_func, &searched);

				if (
					ret != i
					)
					log_test(40 + i)
			}
		}

		ftarray__free(&array);
	}
}
