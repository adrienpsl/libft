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

void test_ft_array$bubble(void)
{
	/*
	* test bad entry
	* */
	{
		t_array *array = ft_array$init(10, sizeof(int));
		int param = 1;
		int ret;

		g_test = 1;
		lib_clear_testbuff();

		// test no array
		{
			ret = ft_array_bubble(NULL, ft_array$func_cmp_int, &param);
			if (!ret
				|| lib_cmp_testbuff(
				"ft_array$bubble error: array ptr (null)\n")
				)
				log_test(0)
		}

		// test no func
		{
			ret = ft_array_bubble(array, NULL, &param);
			if (!ret
				|| lib_cmp_testbuff(
				"ft_array$bubble error: func ptr (null)\n")
				)
				log_test(1)
		}

		// test no param
		{
			ft_array$push(&array, &param);
			ft_array$push(&array, &param);
			ret = ft_array_bubble(array, ft_array$func_cmp_int, NULL);
			if (ret
				|| lib_cmp_testbuff(
				"ft_array$func_cmp_int arg ptr (null)\n")
				)
				log_test(2)
		}

		g_test = 0;
		ft_array$free(&array);
	}

	/*
	* sorting test
	* */
	{
//		t_array *array = ft_array$init(0, sizeof(int));

		// test with 0 number
		{

		}


//		ft_array$free(&array);

	}




}
