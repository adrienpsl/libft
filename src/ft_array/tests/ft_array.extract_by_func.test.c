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

#include <ft_test.h>
#include <ft_array.h>
#include <ft_str.h>

static int			test_func(void *el, void *param)
{
	int *modulo;
	int *nb;

	nb = el;
	modulo = param;

	return !(*nb % *modulo);
}

void	test_ft_array__extract_by_func()
{
	/*
	* test error handling
	* */
	{
		t_array *ret;

		// test no array
		{
			g_test = 1;
			test_clear_testbuff();

			ret = ftarray__extract_by_func(NULL, ftarray__func_print_int, NULL);
			if (
				ret
				|| test_cmp_testbuff_log(
					"ft_array__extract_by_func error: array ptr (null)\n")
				)
				log_test(0)

			t_array *ptr = (t_array *)0x123;
			ret = ftarray__extract_by_func(ptr, NULL, NULL);
			if (
				ret
				|| test_cmp_testbuff_log(
					"ft_array__extract_by_func error: func ptr (null)\n")
				)
				log_test(1)
		}
	}

	/*
	* test all good
	* */
	{
		g_test = 1;
		test_clear_testbuff();
		int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		t_array *array;
		t_array *new;
		int modulo = 1;

		// test one element
		{

			// match
			{
				modulo = 1;
				array = ftarray__init_data(data, 1, sizeof(int));
				new = ftarray__extract_by_func(array, test_func, &modulo);

				ftarray__func(array, ftarray__func_print_int, NULL);
				if (test_cmp_buff("\n"))
					log_test(0)

				ftarray__func(new, ftarray__func_print_int, NULL);
				if (test_cmp_buff("1 \n"))
					log_test(1)

				ftarray__free(&array);
				ftarray__free(&new);
			}

			// no match
			{
				modulo = 2;
				array = ftarray__init_data(data, 1, sizeof(int));
				new = ftarray__extract_by_func(array, test_func, &modulo);

				ftarray__func(array, ftarray__func_print_int, NULL);
				if (test_cmp_buff("1 \n"))
					log_test(2)

				ftarray__func(new, ftarray__func_print_int, NULL);
				if (test_cmp_buff("\n"))
					log_test(3)

				ftarray__free(&array);
				ftarray__free(&new);
			}
		}

		// test two element
		{
			modulo = 2;
			array = ftarray__init_data(data, 4, sizeof(int));
			new = ftarray__extract_by_func(array, test_func, &modulo);

			ftarray__func(array, ftarray__func_print_int, NULL);
			if (test_cmp_buff("1 3 \n"))
				log_test(4)

			ftarray__func(new, ftarray__func_print_int, NULL);
			if (test_cmp_buff("2 4 \n"))
				log_test(5)

			ftarray__free(&array);
			ftarray__free(&new);
		}

		// test 10 element
		{
			modulo = 2;
			array = ftarray__init_data(data, 10, sizeof(int));
			new = ftarray__extract_by_func(array, test_func, &modulo);

			ftarray__func(array, ftarray__func_print_int, NULL);
			if (test_cmp_buff("1 3 5 7 9 \n"))
				log_test(4)

			ftarray__func(new, ftarray__func_print_int, NULL);
			if (test_cmp_buff("2 4 6 8 0 \n"))
				log_test(5)

			ftarray__free(&array);
			ftarray__free(&new);
		}

		g_test = 0;
	}
}
