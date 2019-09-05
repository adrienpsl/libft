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
#include "libft.h"

void test_ft_array_next_and_prev(void)
{
	/*
	* ftarray__next
	* */
	{
		t_array *array = ftarray__init(10, sizeof(int));
		t_array *ret;

		// test null given with all the 4 function
		{
			g_test = 1;
			lib_clear_testbuff();

			ret = ftarray__next(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ftarray__next error: array ptr (null)\n")
				)
				log_test(0)

			ret = ftarray__next_loop(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$next_loop error: array ptr (null)\n")
				)
				log_test(1)

			ret = ftarray__prev(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$prev error: array ptr (null)\n")
				)
				log_test(1)

			ret = ftarray__prev_loop(NULL);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$prev_loop error: array ptr (null)\n")
				)
				log_test(1)
		}
		ftarray__free(&array);
	}

	/*
	* test with 0 element in the array
	* */
	{
		// test next
		{
			t_array *array = ftarray__init(0, sizeof(int));
			void *el;

			array->i = 0;
			el = ftarray__next(array);
			if (
				NULL != el)
				log_test(10)
		}

		// test next_loop
		{
			t_array *array = ftarray__init(0, sizeof(int));
			void *el;

			array->i = 0;
			el = ftarray__next_loop(array);
			if (
				NULL != el)
				log_test(10)
		}

		// test prev
		{
			t_array *array = ftarray__init(0, sizeof(int));
			void *el;

			array->i = 0;
			el = ftarray__prev(array);
			if (
				NULL != el)
				log_test(10)
		}

		// test prev_loop
		{
			t_array *array = ftarray__init(0, sizeof(int));
			void *el;

			array->i = 0;
			el = ftarray__prev_loop(array);
			if (
				NULL != el)
				log_test(10)
		}
	}



	/*
	* test with an array of 5
	* */
	{
		t_array *array = ftarray__init(20, sizeof(int));
		int data[30] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5, 6,
						 7, 8, 9, 10 };
		int *tmp;

		ft_memcpy(array->data, data, sizeof(int) * 11);
		array->length = 11;

		// test next
		{
			for (int i = 0; i < 11; ++i)
			{
				tmp = ftarray__next(array);
				if (!tmp || *tmp != data[i])
					log_test(0)
			}
			tmp = ftarray__next(array);
			if (tmp || array->i != 11)
				log_test(1)
		}

		// test next_loop
		{
			array->i = 0;
			for (int i = 0; i < 20; ++i)
			{
				tmp = ftarray__next_loop(array);
				if (!tmp || *tmp != data[i])
					log_test(2)
			}
		}

		// test prev
		{
			array->i = array->length - 1;
			for (int i = 10; i > -1; --i)
			{
				tmp = ftarray__prev(array);
				if (!tmp || *tmp != data[i])
					log_test(3)
			}
			tmp = ftarray__prev(array);
			if (tmp || array->i != 0)
				log_test(4)
		}

		// test prev_loop
		{
			array->i = array->length - 1;
			for (int i = 21; i > -1; --i)
			{
				tmp = ftarray__prev_loop(array);
				if (!tmp || *tmp != data[i])
					log_test(5)
			}
		}

		ftarray__free(&array);
	}
}
