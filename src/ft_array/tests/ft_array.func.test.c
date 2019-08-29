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
#include <ft_array.h>
#include <ft_str.h>

void test_ft_array$func()
{
	/*
	* test error handling
	* */
	{
		t_array *ret;

		// test no array
		{
			g_test = 1;
			lib_clear_testbuff();

			ret = ftarray__func(NULL, ftarray__func_print_int, NULL);
			if (
				ret
				|| lib_cmp_testbuff_log(
					"ftarray__func error: array ptr (null)\n")
				)
				log_test(0)

			t_array *ptr = (t_array *)0x123;
			ret = ftarray__func(ptr, NULL, NULL);
			if (
				ret
				|| lib_cmp_testbuff_log("ftarray__func error: func ptr (null)\n")
				)
				log_test(1)
		}
	}

	/*
	* test all good 
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ftarray__init_data(data, 10, sizeof(int));
		g_test = 1;

		array->i = 2;
		ftarray__func(array, ftarray__func_print_int, NULL);
		if (ft_str_cmp("0 10 2 2 23 342 0 0 0 0 \n", g_test_buffer))
			log_test(2)

		g_test = 0;
		ftarray__free(&array);
	}
}