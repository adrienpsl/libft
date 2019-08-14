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
#include <ft_array.h>
#include <test.h>
#include <libft.test.h>
#include <ft_mem.h>
#include "libft.h"

void test_ft_array$utils()
{
	/*
	* test ft_array$clear
	* */
	{
		// test error handling
		{
			g_test = 1;
			lib_clear_testbuff();
			ft_array$clear(NULL);
			if (
				lib_cmp_testbuff("ft_array$clear arg ptr (null)\n")
				)
				log_test(0)
		}

		// test all good
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		int data_empty[10] = { 0};
		t_array *array = ft_array$init_data(data, 10, sizeof(int));
		ft_array$clear(array);
		if (
			array->length
			|| array->i
			|| ft_memcmp(data_empty, array->data, sizeof(int) * 10)
			)
			log_test(1)
	}
}