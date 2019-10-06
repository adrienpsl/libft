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

# include "libft.h"


void	test_ft_array_double_size(void);
void	test_ft_array_double_size(void)
{
	/*
	* Error handling
	* */
	{
		int ret;

		// test no array
		{
			g_test = 1;
			test_clear_testbuff();
			ret = ftarray__double_size(NULL);
			if (
				ret != -1
				|| test_cmp_testbuff_log(
					"ftarray__double_size error: array ptr (null)\n")
				)
				log_test(0)
		}
	}

	/*
	* test all good
	* */
	{
		int data[10] = { 0, 10, 2, 2, 23, 342 };
		t_array *array = ftarray__init_data(data, 10, sizeof(int));
		int ret;

		{
			t_array *result = ftarray__init(20, sizeof(int));
			ft_memcpy(result->data, data, sizeof(int) * 10);
			result->length = 10;

			ret = ftarray__double_size(array);

			if (ret
				|| ftarray__cmp(result, array, ftarray__cmp_int)
				|| array->capacity != 20)
				log_test(1)
		}
	}
}
