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
#include <ft_test.h>
#include <ft_test.h>

void test_ft_array$at()
{
	/*
	* ft_array$at : return bad stuff given
	* */
	{
		t_array *array = ftarray__init(1, sizeof(int));
		void *ret;

		g_test = 1;
		test_clear_testbuff();

		// test with no exist value
		{
			// test with negative index
			{
				ret = ftarray__at(array, -10);

				if (ret
					|| test_cmp_testbuff_log(
					"ft_array$at error : index is negative\n")
					)
					log_test(0)
			}

			// test with index bigger
			{
				ret = ftarray__at(array, 2);

				if (ret
					|| test_cmp_testbuff_log(
					"ft_array$at error : index bigger than length\n")
					)
					log_test(1)
			}

			// test with null array
			{
				ret = ftarray__at(NULL, 100);

				if (ret
					|| test_cmp_testbuff_log(
					"ft_array$at error: array ptr (null)\n")
					)
					log_test(2)
			}
		}

		g_test = 0;
		ftarray__free(&array);
	}

	/*
	* ft_array$at : good stuff given
	* */
	{
		t_array *array = ftarray__init(1, sizeof(int));
		void *element;

		// test with an array of 100
		{
			for (int i = 0; i < 100; ++i)
			{
				ftarray__push(array, &i);
			}

			for (int j = 0; j < 100; ++j)
			{
				if (!(element = ftarray__at(array, j)))
				{
					log_test(3)
					break;
				}
				if (*(int *)element != j)
				{
					log_test(4)
				}
			}
		}

		ftarray__free(&array);
	}
}