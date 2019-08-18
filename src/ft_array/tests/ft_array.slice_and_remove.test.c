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
#include "libft.h"

void test_ft_array$slice_and_remove()
{
	/*
	* test error handling
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ft_array$init_data(data, 10, sizeof(int));
		t_array *ret;

		g_test = 1;
		lib_clear_testbuff();

		// null array
		{
			ret = ft_array$slice_and_remove(NULL, 1, 2);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove array ptr (null)\n")
				)
				log_test(0)
		}

		// neg nb
		{
			ret = ft_array$slice_and_remove(array, -1, 2);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at / from  < 0\n")
				)
				log_test(0)

			ret = ft_array$slice_and_remove(array, 1, -2);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at >= from\n")
				)
				log_test(0)
		}

		// nb bigger than limint
		{
			ret = ft_array$slice_and_remove(array, 0, 20);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at / from > length\n")
				)
				log_test(0)

			ret = ft_array$slice_and_remove(array, 20, 21);
			if (ret
				|| lib_cmp_testbuff_log(
				"ft_array$slice_and_remove at / from > length\n")
				)
				log_test(0)
		}
		g_test = 0;
		ft_array$free(&array);
	}

}