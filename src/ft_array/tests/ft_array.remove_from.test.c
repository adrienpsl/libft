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

void test_ft_array$remove_from()
{
	/*
	* test error handling
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ft_array$init_data(data, 10, sizeof(int));

		g_test = 1;
		lib_clear_testbuff();

		// null array
		{
			ft_array$remove_from(NULL, 1, 2);
			if (
				lib_cmp_testbuff_log(
					"ft_array$remove_from array ptr (null)\n")
				)
				log_test(0)
		}

		// neg nb
		{
			ft_array$remove_from(array, -1, 2);
			if (
				lib_cmp_testbuff_log(
					"ft_array$remove_from at / from  < 0\n")
				)
				log_test(0)

			ft_array$remove_from(array, 1, -2);
			if (
				lib_cmp_testbuff_log(
					"ft_array$remove_from at >= from\n")
				)
				log_test(0)
		}

		// nb bigger than limint
		{
			ft_array$remove_from(array, 0, 20);
			if (
				lib_cmp_testbuff_log(
					"ft_array$remove_from at / from >= length\n")
				)
				log_test(0)

			ft_array$remove_from(array, 20, 21);
			if (
				lib_cmp_testbuff_log(
					"ft_array$remove_from at / from >= length\n")
				)
				log_test(0)
		}
		g_test = 0;
		ft_array$free(&array);
	}

	/*
	* test no errror
	* */
	{

		t_array *result;

		// test slice start of the tab
		{
			int data[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			t_array *array = ft_array$init_data(data, 10, sizeof(int));
			result = ft_array$init_data(data + 5, 5, sizeof(int));

			ft_array$remove_from(array, 0, 5);

			if (
				ft_array$cmp(result, array, ft_array$cmp_int)
				)
				log_test(1)
		}

		// test slice start of middle
		{
			int data[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			t_array *array = ft_array$init_data(data, 10, sizeof(int));

			int result_data[12] = { 0, 1, 2, 7, 8, 9 };
			result = ft_array$init_data(result_data, 6, sizeof(int));

			ft_array$remove_from(array, 3, 7);

			if (
				ft_array$cmp(result, array, ft_array$cmp_int)
				)
				log_test(1)
		}

		// test at the end
		{
			int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			t_array *array = ft_array$init_data(data, 10, sizeof(int));

			int result_data[12] = { 0, 1, 2, 3, 4, 5 };
			result = ft_array$init_data(result_data, 5, sizeof(int));

			ft_array$remove_from(array, 5, 10);

			if (
				ft_array$cmp(result, array, ft_array$cmp_int)
				)
				log_test(1)
		}
	}
}
