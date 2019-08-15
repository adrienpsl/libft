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

void test_ft_array_cmp()
{
	/*
	* test error handling
	* */
	{
		t_array *array = ft_array$init(10, sizeof(int));
		int ret;

		g_test = 1;
		lib_clear_testbuff();

		// test with null given
		{
			// null array
			{
				ret = ft_array$cmp(NULL, array, ft_array$cmp_int);
				if (!ret
					|| lib_cmp_testbuff_log(
					"ft_array$cmp error: array ptr (null)\n")
					)
					log_test(0)

				ft_array$cmp(array, NULL, ft_array$cmp_int);
				if (!ret
					|| lib_cmp_testbuff_log(
					"ft_array$cmp error: array ptr (null)\n")
					)
					log_test(1)

				ft_array$cmp(NULL, NULL, ft_array$cmp_int);
				if (!ret
					|| lib_cmp_testbuff_log(
					"ft_array$cmp error: array ptr (null)\n")
					)
					log_test(2)
			}

			// null function
			{
				ft_array$cmp(array, array, NULL);
				if (!ret
					|| lib_cmp_testbuff_log(
					"ft_array$cmp error: func ptr (null)\n")
					)
					log_test(2)
			}
		}

		g_test = 0;
		ft_array$free(&array);
	}

	/*
	* test cmp
	* */
	{
		t_array *array_1 = ft_array$init(1000, sizeof(int));
		t_array *array_2 = ft_array$init(1000, sizeof(int));
		int data_1[20] = { 0, 1, 2, 3, 4, 5 };

		// test 1
		{
			ft_array$push(&array_1, data_1);
			ft_array$push(&array_2, data_1);
			if (ft_array$cmp(array_1, array_2, ft_array$cmp_int))
				log_test(0)

			ft_array$clear(array_1);
			ft_array$push(&array_1, data_1 + 1);
			if (!ft_array$cmp(array_1, array_2, ft_array$cmp_int))
				log_test(1)
		}

		ft_array$clear(array_1);
		ft_array$clear(array_2);
		// test 2
		{
			ft_array$push(&array_1, data_1);
			ft_array$push(&array_2, data_1);
			ft_array$push(&array_1, data_1 + 1);
			ft_array$push(&array_2, data_1 + 1);

			if (ft_array$cmp(array_1, array_2, ft_array$cmp_int))
				log_test(2)

			ft_array$clear(array_1);
			ft_array$push(&array_1, data_1 + 1);
			if (!ft_array$cmp(array_1, array_2, ft_array$cmp_int))
				log_test(3)

			ft_array$free(&array_1);
			ft_array$free(&array_2);
		}



		// test 1000
		{
			int arr_1[1000] = { 0 };
			int arr_2[1000] = { 0 };

			for (int i = -2000; i < 2000; ++i)
			{
				arr_1[lib_random_int(1000)] = i;
				arr_2[lib_random_int(1000)] = i;
			}

			array_1 = ft_array$init_data(arr_1, 1000, sizeof(int));
			array_2 = ft_array$init_data(arr_1, 1000, sizeof(int));

			if (ft_array$cmp(array_1, array_2, ft_array$cmp_int))
				log_test(4)

			ft_array$free(&array_2);
			array_2 = ft_array$init_data(arr_2, 1000, sizeof(int));

			if (!ft_array$cmp(array_1, array_2, ft_array$cmp_int))
				log_test(5)
		}
	}
}
