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
#include "libft.h"

void test_ft_array$slice_and_remove()
{
	/*
	* test error handling
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ft_array$init_data(data, 10, sizeof(int));
		t_array *ret;

		g_test = 1;
		lib_clear_testbuff();

		// null array
		{
			ret = ft_array$slice_and_remove(NULL, 1, 2);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove array ptr (null)\n")
				)
				log_test(0)
		}

		// neg nb
		{
			ret = ft_array$slice_and_remove(array, -1, 2);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at / from  < 0\n")
				)
				log_test(0)

			ret = ft_array$slice_and_remove(array, 1, -2);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at >= from\n")
				)
				log_test(0)
		}

		// nb bigger than limint
		{
			ret = ft_array$slice_and_remove(array, 0, 20);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at / from > length\n")
				)
				log_test(0)

			ret = ft_array$slice_and_remove(array, 20, 21);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at / from > length\n")
				)
				log_test(0)
		}
		g_test = 0;
		ft_array$free(&array);
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
			t_array *array = ft_array$init_data(data, 10, sizeof(int));

			ret = ft_array$slice_and_remove(array, 0, 5);
			result = ft_array$init_data(data, 5, sizeof(int));
			t_array *new_array_res = ft_array$init_data(data + 5, 5,
														sizeof(int));

			if (
				ft_array$cmp(result, ret, ft_array$cmp_int)
				|| ft_array$cmp(new_array_res, array, ft_array$cmp_int)
				)
				log_test(1)
			ft_array$free(&array);
			ft_array$free(&ret);
			ft_array$free(&result);
			ft_array$free(&new_array_res);
		}

		// test slice middle
		{
			t_array *array = ft_array$init_data(data, 10, sizeof(int));

			ret = ft_array$slice_and_remove(array, 2, 7);
			result = ft_array$init_data(data + 2, 5, sizeof(int));
			int new_data[10] = { 0, 1, 7, 8, 9 };
			t_array *new_array_res = ft_array$init_data(new_data, 5,
														sizeof(int));

			if (
				ft_array$cmp(result, ret, ft_array$cmp_int)
				|| ft_array$cmp(new_array_res, array, ft_array$cmp_int)
				)
				log_test(1)

			ft_array$free(&array);
			ft_array$free(&ret);
			ft_array$free(&result);
			ft_array$free(&new_array_res);
		}

		// test slice end
		{
			t_array *array = ft_array$init_data(data, 10, sizeof(int));

			ret = ft_array$slice_and_remove(array, 5, array->length);
			result = ft_array$init_data(data + 5, 5, sizeof(int));
			t_array *new_array_res = ft_array$init_data(data, 5,
														sizeof(int));

			if (
				ft_array$cmp(result, ret, ft_array$cmp_int)
				|| ft_array$cmp(new_array_res, array, ft_array$cmp_int)
				)
				log_test(1)

			ft_array$free(&array);
			ft_array$free(&ret);
			ft_array$free(&result);
			ft_array$free(&new_array_res);
		}
	}
}