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

#include <stddef.h>
#include <test.h>
#include <libft.test.h>
#include <ft_array.h>

void test_ft_array_free()
{
	/*
	* test error handling
	* */
	{
		// test no array
		{
			g_test = 1;
			lib_clear_testbuff();

			ft_array$free(NULL);
			if (
				lib_cmp_testbuff("ft_array$free arg ptr (null)\n")
				)
				log_test(0)

			t_array *test = NULL;
			ft_array$free(&test);
			if (
				lib_cmp_testbuff("ft_array$free arg ptr (null)\n")
				)
				log_test(1)
		}
	}

	/*
	* test all good
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ft_array$init_data(data, 10, sizeof(int));

		ft_array$free(&array);
		if (array)
			log_test(2)
	}
}
