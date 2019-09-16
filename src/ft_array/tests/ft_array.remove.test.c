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

#include <ft_test.h>
#include <ft_test.h>
#include <ft_array.h>
#include "libft.h"

void	test_ft_array_remove()
{
	/*
	* test error handling
	* */
	{
		int ret;
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ftarray__init_data(data, 10, sizeof(int));

		// test no array
		{
			g_test = 1;
			test_clear_testbuff();

			// test no array
			{
				ret = ftarray__remove(NULL, 10);
				if (
					!ret
					|| test_cmp_testbuff_log(
						"ftarray__remove error: array ptr (null)\n")
					)
					log_test(0)
			}

			// test index negatif
			{
				ret = ftarray__remove(array, -42);
				if (
					!ret
					|| test_cmp_testbuff_log(
						"ftarray__remove index bigger than length/neg\n")
					)
					log_test(1)
			}

			// test index bigger than length
			{
				ret = ftarray__remove(array, 11);
				if (
					!ret
					|| test_cmp_testbuff_log(
						"ftarray__remove index bigger than length/neg\n")
					)
					log_test(2)
			}

			// test index negatif
			{
				ret = ftarray__remove(array, -42);
				if (
					!ret
					|| test_cmp_testbuff_log(
						"ftarray__remove index bigger than length/neg\n")
					)
					log_test(3)

				ftarray__free(&array);
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

		t_array *array = ftarray__init_data(data, 10, sizeof(int));

		// test remove first 2 times
		{
			int data_test[10] = { 2, 3, 4, 5, 6, 7, 8, 9 };
			t_array *result = ftarray__init_data(data_test, 8, sizeof(int));

			int ret_1 = ftarray__remove(array, 0);
			int ret_2 = ftarray__remove(array, 0);

			if (
				ret_1 || ret_2 || array->length != 8
				|| ftarray__cmp(array, result, ftarray__cmp_int)
				)
				log_test(4)
		}

		// test remove last 2 times
		{
			int data_test[10] = { 2, 3, 4, 5, 6, 7 };
			t_array *result = ftarray__init_data(data_test, 6, sizeof(int));

			int ret_1 = ftarray__remove(array, array->length - 1);
			int ret_2 = ftarray__remove(array, array->length - 1);

			if (
				ret_1 || ret_2 || array->length != 6
				|| ftarray__cmp(array, result, ftarray__cmp_int)
				)
				log_test(4)
		}

		// test remove 2 in the middle
		{
			int data_test[10] = { 2, 3, 6, 7 };
			t_array *result = ftarray__init_data(data_test, 4, sizeof(int));

			int ret_1 = ftarray__remove(array, 2);
			int ret_2 = ftarray__remove(array, 2);

			if (
				ret_1 || ret_2 || array->length != 4
				|| ftarray__cmp(array, result, ftarray__cmp_int)
				)
				log_test(5)
		}

		// test remove 3 pieces
		{
			int data_test[10] = { 2 };
			t_array *result = ftarray__init_data(data_test, 1, sizeof(int));

			int ret_1 = ftarray__remove(array, 3);
			int ret_2 = ftarray__remove(array, 2);
			int ret_3 = ftarray__remove(array, 1);

			if (
				ret_1 || ret_2 || ret_3 || array->length != 1
				|| ftarray__cmp(array, result, ftarray__cmp_int)
				)
				log_test(5)
		}

		// test remove the last one and test protection if empty
		{
			int ret_1 = ftarray__remove(array, 0);
			if (
				ret_1 || array->length
				)
				log_test(6)

			g_test = 1;
			ret_1 = ftarray__remove(array, 0);
			if (!ret_1 || test_cmp_testbuff_log(
				"ftarray__remove index bigger than length/neg\n"))
				log_test(7)

			g_test = 0;
		}
	}
}
