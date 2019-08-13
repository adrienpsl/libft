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

static int cmp(void const *a, void const *b)
{
	int const *pa = a;
	int const *pb = b;

	return *pa - *pb;
}

static int inv_cmp(void const *a, void const *b)
{
	int const *pa = a;
	int const *pb = b;

	return *pb - *pa;
}

void test_ft_array$bubble(void)
{
	/*
	* test bad entry
	* */
	{
		t_array *array = ft_array$init(10, sizeof(int));
		int param = 1;
		int ret;

		g_test = 1;
		lib_clear_testbuff();

		// test no array
		{
			ret = ft_array$bubble(NULL, ft_array$func_cmp_int, &param);
			if (!ret
				|| lib_cmp_testbuff(
				"ft_array$bubble error: array ptr (null)\n")
				)
				log_test(0)
		}

		// test no func
		{
			ret = ft_array$bubble(array, NULL, &param);
			if (!ret
				|| lib_cmp_testbuff(
				"ft_array$bubble error: func ptr (null)\n")
				)
				log_test(1)
		}

		// test no param
		{
			ft_array$push(&array, &param);
			ft_array$push(&array, &param);
			ret = ft_array$bubble(array, ft_array$func_cmp_int, NULL);
			if (ret
				|| lib_cmp_testbuff(
				"ft_array$func_cmp_int arg ptr (null)\n")
				)
				log_test(2)
		}

		g_test = 0;
		ft_array$free(&array);
	}

	/*
	* sorting test
	* */
	{
		t_array *array = ft_array$init(10, sizeof(int));
		int order = 1;
		int ret;

		// test with 0 number
		{
			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);
			if (ret)
				log_test(3)
		}

		// test with 1 number
		{
			int n_1 = 1;
			ft_array$push(&array, &n_1);

			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);
			if (ret)
				log_test(4)
		}

		// test with 2 numbers sorted
		{
			int n_1 = 2;
			ft_array$push(&array, &n_1);

			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);
			if (ret)
				log_test(5)
		}

		// test with 2 numbers unsorted
		{
			ft_array_clear(array);
			int n_1 = 2;
			int n_2 = 1;
			ft_array$push(&array, &n_1);
			ft_array$push(&array, &n_2);

			int res_array[10] = { 1, 2 };

			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 2))
				log_test(6)
		}

		// test with 3 numbers unsorted
		{
			ft_array_clear(array);
			int n_1 = 2;
			int n_2 = 1;
			int n_3 = -3;
			ft_array$push(&array, &n_1);
			ft_array$push(&array, &n_2);
			ft_array$push(&array, &n_3);

			int res_array[10] = { -3, 1, 2 };

			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 4))
				log_test(7)
		}

		// test with 3 numbers unsorted inverted sort
		{
			ft_array_clear(array);
			int n_1 = 2;
			int n_2 = 1;
			int n_3 = -3;
			ft_array$push(&array, &n_1);
			ft_array$push(&array, &n_2);
			ft_array$push(&array, &n_3);

			int res_array[10] = { 2, 1, -3 };

			order = 0;
			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 4))
				log_test(8)
		}

		// test with 2 numbers unsorted inverted sort
		{
			ft_array_clear(array);
			int n_1 = 2;
			int n_2 = 1;
			ft_array$push(&array, &n_1);
			ft_array$push(&array, &n_2);

			int res_array[10] = { 2, 1 };

			order = 0;
			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 4))
				log_test(9)
		}

		ft_array$free(&array);
	}

	/*
	* test with big table
	* */
	{
		t_array *array = ft_array$init(1000, sizeof(int));
		int data_arr[1000] = { 0 };
		int ret;

		// test with 1000 nb little first
		{
			// build the array
			for (int i = -2000; i < 2000; ++i)
			{
				data_arr[lib_random_int(1000)] = i;
			}

			// copy it in the array
			ft_memcpy(array->data, data_arr, sizeof(int) * 1000);
			array->length = 1000;

			// do sort
			qsort(data_arr, 1000, sizeof(int), cmp);
			int order = 1;
			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);

			if (ret ||
				ft_memcmp(data_arr, array->data, sizeof(int) * 1000)
				)
				log_test(10)
		}

		{
			// build the bigger first
			for (int i = -2000; i < 2000; ++i)
			{
				data_arr[lib_random_int(1000)] = i;
			}

			// copy it in the array
			ft_memcpy(array->data, data_arr, sizeof(int) * 1000);
			array->length = 1000;

			// do sort
			qsort(data_arr, 1000, sizeof(int), inv_cmp);
			int order = 0;
			ret = ft_array$bubble(array, ft_array$func_cmp_int, &order);

			if (ret ||
				ft_memcmp(data_arr, array->data, sizeof(int) * 1000)
				)
				log_test(11)
		}

		ft_array$free(&array);
	}
}
