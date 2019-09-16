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

void	test_ft_array$cmp()
{
	/*
	* test error handling
	* */
	{
		t_array *array = ftarray__init(10, sizeof(int));
		int ret;

		g_test = 1;
		test_clear_testbuff();

		// test with null given
		{
			// null array
			{
				ret = ftarray__cmp(NULL, array, ftarray__cmp_int);
				if (!ret
					|| test_cmp_testbuff_log(
					"ft_array$cmp error: array ptr (null)\n")
					)
					log_test(0)

				ftarray__cmp(array, NULL, ftarray__cmp_int);
				if (!ret
					|| test_cmp_testbuff_log(
					"ft_array$cmp error: array ptr (null)\n")
					)
					log_test(1)

				ftarray__cmp(NULL, NULL, ftarray__cmp_int);
				if (!ret
					|| test_cmp_testbuff_log(
					"ft_array$cmp error: array ptr (null)\n")
					)
					log_test(2)
			}

			// null function
			{
				ftarray__cmp(array, array, NULL);
				if (!ret
					|| test_cmp_testbuff_log(
					"ft_array$cmp error: func ptr (null)\n")
					)
					log_test(2)
			}
		}

		g_test = 0;
		ftarray__free(&array);
	}

	/*
	* test with array of 0
	* */
	{
		// both 0 element
		{
			t_array *array_1 = ftarray__init(0, sizeof(int));
			t_array *array_2 = ftarray__init(0, sizeof(int));
			if (ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(-1)
		}

		// one 0 element
		{
			int data_1[20] = { 0, 1, 2, 3, 4, 5 };
			t_array *array_1 = ftarray__init_data(data_1, 6, sizeof(int));
			t_array *array_2 = ftarray__init(0, sizeof(int));
			if (1 != ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(-2)
		}
	}


	/*
	* test cmp
	* */
	{
		t_array *array_1 = ftarray__init(1000, sizeof(int));
		t_array *array_2 = ftarray__init(1000, sizeof(int));
		int data_1[20] = { 0, 1, 2, 3, 4, 5 };

		// test 1
		{
			ftarray__push(array_1, data_1);
			ftarray__push(array_2, data_1);
			if (ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(0)

			ftarray__clear(array_1);
			ftarray__push(array_1, data_1 + 1);
			if (!ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(1)
		}

		ftarray__clear(array_1);
		ftarray__clear(array_2);
		// test 2
		{
			ftarray__push(array_1, data_1);
			ftarray__push(array_2, data_1);
			ftarray__push(array_1, data_1 + 1);
			ftarray__push(array_2, data_1 + 1);

			if (ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(2)

			ftarray__clear(array_1);
			ftarray__push(array_1, data_1 + 1);
			if (!ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(3)

			ftarray__free(&array_1);
			ftarray__free(&array_2);
		}



		// test 1000
		{
			int arr_1[1000] = { 0 };
			int arr_2[1000] = { 0 };

			for (int i = -2000; i < 2000; ++i)
			{
				arr_1[test_random_int(1000)] = i;
				arr_2[test_random_int(1000)] = i;
			}

			array_1 = ftarray__init_data(arr_1, 1000, sizeof(int));
			array_2 = ftarray__init_data(arr_1, 1000, sizeof(int));

			if (ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(4)

			ftarray__free(&array_2);
			array_2 = ftarray__init_data(arr_2, 1000, sizeof(int));

			if (!ftarray__cmp(array_1, array_2, ftarray__cmp_int))
				log_test(5)
		}
	}
}
