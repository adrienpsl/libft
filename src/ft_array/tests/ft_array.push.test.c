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
#include <test.h>
#include <stdio.h>
#include <ft_str.h>
#include <ft_mem.h>
#include <libft.test.h>

void test_ft_array$add()
{
	/*
	 * ft_array_push : add 1000 nb
	 * */
	{
		t_array *array = ft_array$init(1, sizeof(int));

		// test if I add 1000 number
		{
			for (int i = 0; i < 1000; ++i)
			{
				ft_array$push(&array, &i);
			}
			// I assign now because the array is variable
			int *int_arr = (void *) array->data;

			if (
				int_arr[0] != 0
				|| int_arr[999] != 999
				|| array->length != 1000
				)
				log_test(0)
		}
		ft_array$free(&array);
	}

	/*
	* ft_array$push : add 1000 string
	* */
	{
		t_array *array = ft_array$init(1, sizeof(char *));
		char *string = "toto";

		// test if I add 1000 number
		{
			for (int i = 0; i < 1000; ++i)
			{
				ft_array$push(&array, &string);
			}
			// I assign now because the array is variable
			char **str_arr = (char **) array->data;

			if (
				ft_str_cmp(str_arr[0], string)
				|| ft_str_cmp(str_arr[999], string)
				|| array->length != 1000
				)
				log_test(1)
		}
		//			ft_array$func(array, ft_array$func_print_str, NULL);
		ft_array$free(&array);
	}


	/*
	* ft_array$push_at : add 1000 nb
	* */
	{
		t_array *array = ft_array$init(1, sizeof(int));

		// test if I add 1000 number
		{
			for (int i = 0; i < 1000; ++i)
			{
				ft_array$push_at(&array, &i, i);
			}
			// I assign now because the array is variable
			int *int_arr = (void *) array->data;

			if (
				int_arr[0] != 0
				|| int_arr[999] != 999
				|| array->length != 1000
				)
				log_test(2)
		}
		ft_array$free(&array);
	}

	/*
	* ft_array$push_at : add and check if number are right positioning
	* */
	{
		t_array *array = ft_array$init(1, sizeof(int));
		int data;

		// test number at middle
		{
			data = 2;
			ft_array$push_at(&array, &data, 0);
			data = 3;
			ft_array$push_at(&array, &data, 1);
			data = 1;
			ft_array$push_at(&array, &data, 0);
			int ref_array[10] = { 1, 2, 3 };
			if (ft_memcmp(ref_array, array->data, sizeof(int) * 4))
				log_test(3)
		}

		// add 2 number at each side of the previous one
		{
			data = 42;
			ft_array$push_at(&array, &data, 0);
			ft_array$push_at(&array, &data, 4);

			int ref_array[10] = { 42, 1, 2, 3, 42 };
			if (ft_memcmp(ref_array, array->data, sizeof(int) * 5))
				log_test(4)
		}
		ft_array$free(&array);
	}

	/*
	* ft_array$push_at : test with bad index
	* */
	{
		t_array *array = ft_array$init(1, sizeof(int));
		int data;
		int ret;

		// active gtest to catch the output and clean buffer
		g_test = 1;
		lib_clear_testbuff();

		// test with to big index
		{
			data = 42;
			ret = ft_array$push_at(&array, &data, 1);
			if (
				ret != -1
				|| array->length
				|| *(int*)array->data
				|| ft_str_cmp(g_test_buffer,
					"/Users/adpusel/code/42/libft/src/ft_array/ft_array.add_at.c:26 index bigger than length\n"
					)
				)
			{
				log_test(5)
			}
		}
		g_test = 0;
		ft_array$free(&array);
	}

}