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

#include <test.h>
#include <libft.test.h>
#include <ft_array.h>
#include <ft_str.h>
#include "libft.h"

void test_ft_array_remove()
{
	/*
	* test error handling
	* */
	{
		int ret;
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ft_array$init_data(data, 10, sizeof(int));

		// test no array
		{
			g_test = 1;
			lib_clear_testbuff();

			// test no array
			{
				ret = ft_array$remove(NULL, 10);
				if (
					!ret
					|| lib_cmp_testbuff(
						"ft_array$remove error: array ptr (null)\n")
					)
					log_test(0)
			}

			// test index negatif
			{
				ret = ft_array$remove(array, -42);
				if (
					!ret
					|| lib_cmp_testbuff(
						"ft_array$remove index bigger than length/neg\n")
					)
					log_test(1)
			}

			// test index bigger than length
			{
				ret = ft_array$remove(array, 11);
				if (
					!ret
					|| lib_cmp_testbuff(
						"ft_array$remove index bigger than length/neg\n")
					)
					log_test(2)
			}

			// test index negatif
			{
				ret = ft_array$remove(array, -42);
				if (
					!ret
					|| lib_cmp_testbuff(
						"ft_array$remove index bigger than length/neg\n")
					)
					log_test(3)

				ft_array$free(&array);
				g_test = 0;
			}
		}
	}

	/*
	* test all good 
	* */
	{
		//		int ret;
		int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		t_array *array = ft_array$init_data(data, 10, sizeof(int));

		// test remove first 2 times
		{
			int data_test[10] = { 2, 3, 4, 5, 6, 7, 8, 9 };
			t_array *result = ft_array$init_data(data_test, 8, sizeof(int));

			int ret_1 = ft_array$remove(array, 0);
			int ret_2 = ft_array$remove(array, 0);

			if (
				ret_1 || ret_2 || array->length != 8
				|| ft_array$cmp(array, result, ft_array$cmp_int)
				)
				log_test(4)
		}

		// test remove last 2 times
		{
			int data_test[10] = { 2, 3, 4, 5, 6, 7 };
			t_array *result = ft_array$init_data(data_test, 6, sizeof(int));

			int ret_1 = ft_array$remove(array, array->length - 1);
			int ret_2 = ft_array$remove(array, array->length - 1);

			if (
				ret_1 || ret_2 || array->length != 6
				|| ft_array$cmp(array, result, ft_array$cmp_int)
				)
				log_test(4)
		}

		// test remove 2 in the middle
		{
			int data_test[10] = { 2, 3, 6, 7 };
			t_array *result = ft_array$init_data(data_test, 4, sizeof(int));

			int ret_1 = ft_array$remove(array, 2);
			int ret_2 = ft_array$remove(array, 2);

			if (
				ret_1 || ret_2 || array->length != 4
				|| ft_array$cmp(array, result, ft_array$cmp_int)
				)
				log_test(5)
		}

		// test remove 3 pieces
		{
			int data_test[10] = { 2 };
			t_array *result = ft_array$init_data(data_test, 1, sizeof(int));

			int ret_1 = ft_array$remove(array, 3);
			int ret_2 = ft_array$remove(array, 2);
			int ret_3 = ft_array$remove(array, 1);

			if (
				ret_1 || ret_2 || ret_3 || array->length != 1
				|| ft_array$cmp(array, result, ft_array$cmp_int)
				)
				log_test(5)
		}

		// test remove the last one and test protection if empty
		{
			int ret_1 = ft_array$remove(array, 0);
			if (
				ret_1 || array->length
				)
				log_test(6)

			g_test = 1;
			ret_1 = ft_array$remove(array, 0);
			if (!ret_1 || lib_cmp_testbuff("ft_array$remove index bigger than length/neg\n"))
			    log_test(7)

			g_test = 0;
		}
	}
}
