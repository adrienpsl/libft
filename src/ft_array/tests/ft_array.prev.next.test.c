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

#include <ft_array.h>
#include <libft.test.h>
#include <test.h>
#include <ft_mem.h>
#include "libft.h"

void test_ft_array_next_and_prev(void)
{
	/*
	* ft_array$next
	* */
	{
		t_array *array = ft_array$init(10, sizeof(int));
		t_array *ret;

		// test null given with all the 4 function
		{
			g_test = 1;
			lib_clear_testbuff();

			ret = ft_array$next(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$next error: array ptr (null)\n")
				)
				log_test(0)

			ret = ft_array$next_loop(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$next_loop error: array ptr (null)\n")
				)
				log_test(1)

			ret = ft_array$prev(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$prev error: array ptr (null)\n")
				)
				log_test(1)

			ret = ft_array$prev_loop(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$prev_loop error: array ptr (null)\n")
				)
				log_test(1)
		}
		ft_array$free(&array);
	}

	/*
	* test with an array of 5
	* */
	{
		t_array *array = ft_array$init(20, sizeof(10));
		int data[30] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5, 6,
						 7, 8, 9, 10 };
		int *tmp;

		ft_memcpy(array->data, data, sizeof(int) * 11);
		array->length = 11;

		// test next
		{
			for (int i = 0; i < 11; ++i)
			{
				tmp = ft_array$next(array);
				if (!tmp || *tmp != data[i])
					log_test(0)
			}
			tmp = ft_array$next(array);
			if (tmp || array->i != 11)
				log_test(1)
		}

		// test next_loop
		{
			array->i = 0;
			for (int i = 0; i < 20; ++i)
			{
				tmp = ft_array$next_loop(array);
				if (!tmp || *tmp != data[i])
					log_test(2)
			}
		}

		// test prev
		{
			array->i = array->length - 1;
			for (int i = 10; i > -1; --i)
			{
				tmp = ft_array$prev(array);
				if (!tmp || *tmp != data[i])
					log_test(3)
			}
			tmp = ft_array$prev(array);
			if (tmp || array->i != 0)
				log_test(4)
		}

		// test prev_loop
		{
			array->i = array->length - 1;
			for (int i = 21; i > -1; --i)
			{
				tmp = ft_array$prev_loop(array);
				if (!tmp || *tmp != data[i])
					log_test(5)
			}
		}

		ft_array$free(&array);
	}
}
