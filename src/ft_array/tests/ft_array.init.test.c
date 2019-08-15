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

# include <ft_array.h>
#include <stdint.h>
#include <test.h>
#include <libft.test.h>
# include "stdio.h"

/*
 * I will test the initialisation is good performed
 * */
void test_ft_array_init(void)
{
	// check good information in array
	{
		int size = 3;
		t_array *array = ft_array$init(size, sizeof(int));

		if (
			array->element_size != sizeof(int)
			|| array->length != 0
			|| array->capacity != size * 2
			)
			log_test(0)
	}

	// look if buffer and array are at the right place
	{
		int size = 3;
		t_array *array = ft_array$init(size, sizeof(int));

		// test data placement
		{
			if (
				array->data != (char *)array + (sizeof(t_array))
				)
				log_test(1)
		}

		// test buffer placement
		{
			char *tmp = array->data;
			tmp += sizeof(int) * (size * 2);
			tmp += sizeof(int);

			if (
				array->buffer != tmp
				)
				log_test(2)
		}

		ft_array$free(&array);
	}

	// test fill
	{
		int size = 3;
		t_array *array = ft_array$init(size, sizeof(int));
		int *int_array = (int *)array->data;

		// test fill array
		{
			*(int *)(array->data + sizeof(2)) = INT32_MAX;

			if (
				int_array[1] != INT32_MAX
				|| int_array[0]
				|| int_array[2]
				)
				log_test(3)
		}

		// test buffer
		{
			*(int *)array->buffer = INT32_MIN;

			if (
				int_array[size * 2 + 1] != INT32_MIN
				)
				log_test(4)
		}

		ft_array$free(&array);
	}

	/*
	* test if bad arguments
	* */
	{
		t_array *array;
		g_test = 1;

		// test no elements
		{
			array = ft_array$init(0, 42);
			if (
				array
				|| lib_cmp_testbuff_log("ft_array$init : no elements number\n")
				)
				log_test(5)

			array = ft_array$init(-22, 42);
			if (
				array
				|| lib_cmp_testbuff_log("ft_array$init : no elements number\n")
				)
				log_test(6)
		}

		// test no element size
		{
			array = ft_array$init(11, 0);
			if (
				array
				|| lib_cmp_testbuff_log("ft_array$init : element size (null)\n")
				)
				log_test(7)
		}

		g_test = 0;
	}

	/*
	* test init_data error
	* */
	{
		t_array *array;
		{
			g_test = 1;
			lib_clear_testbuff();

			{
				array = ft_array$init_data(NULL, 10, 10);
				if (
					array
					||
						lib_cmp_testbuff_log(
							"ft_array$init_data : start (null)\n")
					)
					log_test(8)
			}


			// test with array of 0
			{
				int test_arr[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
				array = ft_array$init_data(test_arr, 0, 4);
				if (
					array
					||
						lib_cmp_testbuff_log(
							"ft_array$init : no elements number\n")
					)
					log_test(9)
			}

			g_test = 0;
		}
	}

	/*
	* test init_data no error
	* */
	{
		t_array *array;
		int test_arr[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		// test with 1 element
		{
			array = ft_array$init_data(test_arr, 1, sizeof(int));
			if (
				!array
				|| *(int *)array->data != 0
				|| array->length != 1
				)
				log_test(10)
			ft_array$free(&array);
		}

		// test with 2 element
		{
			array = ft_array$init_data(test_arr, 2, sizeof(int));
			if (
				!array
				|| *(int *)array->data != 0
				|| *((int *)array->data + 1) != 1
				|| array->length != 2
				)
				log_test(11)
			ft_array$free(&array);
		}
	}
}
