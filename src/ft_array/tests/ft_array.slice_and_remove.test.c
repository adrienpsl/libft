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


void	test_ft_array$slice_and_remove(void);
void	test_ft_array$slice_and_remove(void)
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
			ret = ftarray__slice_and_remove(NULL, 1, 2);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice_and_remove array ptr (null)\n")
				)
				log_test(0)
		}

		// neg nb
		{
			ret = ftarray__slice_and_remove(array, -1, 2);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice_and_remove at / from  < 0\n")
				)
				log_test(0)

			ret = ftarray__slice_and_remove(array, 1, -2);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice_and_remove at >= from\n")
				)
				log_test(0)
		}

		// nb bigger than limint
		{
			ret = ftarray__slice_and_remove(array, 0, 20);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice_and_remove at / from > length\n")
				)
				log_test(0)

			ret = ftarray__slice_and_remove(array, 20, 21);
			if (ret
				|| test_cmp_testbuff_log(
				"ftarray__slice_and_remove at / from > length\n")
				)
				log_test(0)
		}
		g_test = 0;
		ftarray__free(&array);
	}


	/*
	* test no error
	* */
	{
		int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		t_array *result;
		t_array *ret;

		// test slice start of the tab
		{
			t_array *array = ftarray__init_data(data, 10, sizeof(int));

			ret = ftarray__slice_and_remove(array, 0, 5);
			result = ftarray__init_data(data, 5, sizeof(int));
			t_array *new_array_res = ftarray__init_data(data + 5, 5,
				sizeof(int));

			if (
				ftarray__cmp(result, ret, ftarray__cmp_int)
				|| ftarray__cmp(new_array_res, array, ftarray__cmp_int)
				)
				log_test(1)
			ftarray__free(&array);
			ftarray__free(&ret);
			ftarray__free(&result);
			ftarray__free(&new_array_res);
		}

		// test slice middle
		{
			t_array *array = ftarray__init_data(data, 10, sizeof(int));

			ret = ftarray__slice_and_remove(array, 2, 7);
			result = ftarray__init_data(data + 2, 5, sizeof(int));
			int new_data[10] = { 0, 1, 7, 8, 9 };
			t_array *new_array_res = ftarray__init_data(new_data, 5,
				sizeof(int));

			if (
				ftarray__cmp(result, ret, ftarray__cmp_int)
				|| ftarray__cmp(new_array_res, array, ftarray__cmp_int)
				)
				log_test(1)

			ftarray__free(&array);
			ftarray__free(&ret);
			ftarray__free(&result);
			ftarray__free(&new_array_res);
		}

		// test slice end
		{
			t_array *array = ftarray__init_data(data, 10, sizeof(int));

			ret = ftarray__slice_and_remove(array, 5, array->length);
			result = ftarray__init_data(data + 5, 5, sizeof(int));
			t_array *new_array_res = ftarray__init_data(data, 5,
				sizeof(int));

			if (
				ftarray__cmp(result, ret, ftarray__cmp_int)
				|| ftarray__cmp(new_array_res, array, ftarray__cmp_int)
				)
				log_test(1)

			ftarray__free(&array);
			ftarray__free(&ret);
			ftarray__free(&result);
			ftarray__free(&new_array_res);
		}
	}
}