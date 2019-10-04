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
# include "ft_array.test.h"

void	test_ft_array_free()
{
	/*
	* test error handling
	* */
	{
		// test no array
		{
			g_test = 1;
			test_clear_testbuff();

			ftarray__free(NULL);
			if (
				test_cmp_testbuff_log("ft_array$free arg ptr (null)\n")
				)
				log_test(0)

			t_array *test = NULL;
			ftarray__free(&test);
			if (
				test_cmp_testbuff_log("ft_array$free arg ptr (null)\n")
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

		ftarray__free(&array);
		if (array)
			log_test(2)
	}
}
