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
#include <ft_test.h>
#include <ft_test.h>

void	test_ft_array$slice()
{
	/*
	* test error handling
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ftarray__init_data(data, 10, sizeof(int));
		t_array *ret;

		g_test = 1;
		test_clear_testbuff();

		// null array
		{
			ret = ftarray__slice(NULL, 1, 2);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice array ptr (null)\n")
				)
				log_test(0)
		}

		// neg nb
		{
			ret = ftarray__slice(array, -1, 2);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice at / from  < 0\n")
				)
				log_test(0)

			ret = ftarray__slice(array, 1, -2);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice at >= from\n")
				)
				log_test(0)
		}

		// nb bigger than limint
		{
			ret = ftarray__slice(array, 0, 20);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice at / from > length\n")
				)
				log_test(0)

			ret = ftarray__slice(array, 20, 21);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice at / from > length\n")
				)
				log_test(0)
		}
		g_test = 0;
		ftarray__free(&array);
	}

	/*
	* test no errror
	* */
	{
		int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		t_array *array = ftarray__init_data(data, 10, sizeof(int));
		t_array *result;
		t_array *ret;

		// test slice start of the tab
		{
			ret = ftarray__slice(array, 0, 5);
			result = ftarray__init_data(data, 5, sizeof(int));

			if (
				ftarray__cmp(result, ret, ftarray__cmp_int)
				)
				log_test(1)
		}

		// test slice start of middle
		{
			ret = ftarray__slice(array, 2, 7);
			result = ftarray__init_data(data + 2, 5, sizeof(int));

			if (
				ftarray__cmp(result, ret, ftarray__cmp_int)
				)
				log_test(1)
		}

		// test at the end
		{
			ret = ftarray__slice(array, 2, 10);
			result = ftarray__init_data(data + 2, 8, sizeof(int));

			if (
				ftarray__cmp(result, ret, ftarray__cmp_int)
				)
				log_test(1)
		}
	}
}
