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
		t_array *array = ftarray__init(10, sizeof(int));
		int param = 1;
		int ret;

		g_test = 1;
		lib_clear_testbuff();

		// test no array
		{
			ret = ftarray__sort_bubble(NULL, ftarray__sort_cmp_int, &param);
			if (!ret
				|| lib_cmp_testbuff_log(
				"ft_array$sort_bubble error: array ptr (null)\n")
				)
				log_test(0)
		}

		// test no func
		{
			ret = ftarray__sort_bubble(array, NULL, &param);
			if (!ret
				|| lib_cmp_testbuff_log(
				"ft_array$sort_bubble error: func ptr (null)\n")
				)
				log_test(1)
		}

		// test no param
		{
			ftarray__push(array, &param);
			ftarray__push(array, &param);
			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$sort_cmp_int arg ptr (null)\n")
				)
				log_test(2)
		}

		g_test = 0;
		ftarray__free(&array);
	}

	/*
	* sorting test
	* */
	{
		t_array *array = ftarray__init(10, sizeof(int));
		int order = 1;
		int ret;

		// test with 0 number
		{
			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);
			if (ret)
				log_test(3)
		}

		// test with 1 number
		{
			int n_1 = 1;
			ftarray__push(array, &n_1);

			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);
			if (ret)
				log_test(4)
		}

		// test with 2 numbers sorted
		{
			int n_1 = 2;
			ftarray__push(array, &n_1);

			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);
			if (ret)
				log_test(5)
		}

		// test with 2 numbers unsorted
		{
			ftarray__clear(array);
			int n_1 = 2;
			int n_2 = 1;
			ftarray__push(array, &n_1);
			ftarray__push(array, &n_2);

			int res_array[10] = { 1, 2 };

			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 2))
				log_test(6)
		}

		// test with 3 numbers unsorted
		{
			ftarray__clear(array);
			int n_1 = 2;
			int n_2 = 1;
			int n_3 = -3;
			ftarray__push(array, &n_1);
			ftarray__push(array, &n_2);
			ftarray__push(array, &n_3);

			int res_array[10] = { -3, 1, 2 };

			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 4))
				log_test(7)
		}

		// test with 3 numbers unsorted inverted sort
		{
			ftarray__clear(array);
			int n_1 = 2;
			int n_2 = 1;
			int n_3 = -3;
			ftarray__push(array, &n_1);
			ftarray__push(array, &n_2);
			ftarray__push(array, &n_3);

			int res_array[10] = { 2, 1, -3 };

			order = 0;
			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 4))
				log_test(8)
		}

		// test with 2 numbers unsorted inverted sort
		{
			ftarray__clear(array);
			int n_1 = 2;
			int n_2 = 1;
			ftarray__push(array, &n_1);
			ftarray__push(array, &n_2);

			int res_array[10] = { 2, 1 };

			order = 0;
			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);
			if (ret || ft_memcmp(res_array, array->data, sizeof(int) * 4))
				log_test(9)
		}

		ftarray__free(&array);
	}

	/*
	* test with big table
	* */
	{
		t_array *array = ftarray__init(1000, sizeof(int));
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
			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);

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
			ret = ftarray__sort_bubble(array, ftarray__sort_cmp_int, &order);

			if (ret ||
				ft_memcmp(data_arr, array->data, sizeof(int) * 1000)
				)
				log_test(11)
		}

		ftarray__free(&array);
	}
}
