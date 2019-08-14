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
#include <ft_array.h>
#include <libft.test.h>
#include <ft_mem.h>
#include "libft.h"

void test_ft_array_double_size()
{
	/*
	* Error handling
	* */
	{
		t_array *ret;

		// test no array
		{
			g_test = 1;
			lib_clear_testbuff();
			ret = ft_array$double_size(NULL);
			if (
				ret
				|| lib_cmp_testbuff(
					"ft_array$double size error: array ptr (null)\n")
				)
				log_test(0)
		}
	}

	/*
	* test all good
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ft_array$init_data(data, 10, sizeof(int));
		t_array *ret;

		{
			t_array *result = ft_array$init(20, sizeof(int));
			ft_memcpy(result->data, data, sizeof(int) * 10);
			result->length = 10;

			ret = ft_array$double_size(array);

			if (ft_array$cmp(result, ret, ft_array$cmp_int)
			|| ret->capacity != 10 * 2 * 2)
				log_test(1)
		}
	}
}
