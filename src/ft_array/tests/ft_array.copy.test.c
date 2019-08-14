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

void test_ft_array$copy()
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
			ret = ft_array$copy(NULL);
			if (
				ret
				|| lib_cmp_testbuff("ft_array$copy error: array ptr (null)\n")
				)
				log_test(0)
		}
	}

	/*
	* test ft_array_copy no errors
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ft_array$init_data(data, 10, sizeof(int));
		t_array *ret;

		{
			ret = ft_array$copy(array);
			if (ft_array$cmp(array, ret, ft_array$cmp_int))
				log_test(1)
		}
	}
}
