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
#include <test.h>
#include <stdio.h>
#include <ft_str.h>
#include <stdlib.h>

void test_ft_array_add()
{
		// add 1000 nb in the array
		{
			t_array *array = ft_array_init(1, sizeof(int));

			// test if I add 1000 number
			{
				for (int i = 0; i < 1000; ++i)
				{
					ft_array_add(&array, &i);
				}
				// I assign now because the array is variable
				int *int_arr = (void *) array->data;

				if (
					int_arr[0] != 0
					|| int_arr[999] != 999
					|| array->length != 1000
					)
					log_test(0)
			}
			ft_array_free(&array);
		}

		// test with  1000 string
		{
			t_array *array = ft_array_init(1, sizeof(char *));
			char *string = "toto";

			// test if I add 1000 number
			{
				for (int i = 0; i < 1000; ++i)
				{
					ft_array_add(&array, &string);
				}
				// I assign now because the array is variable
				char **str_arr = (char **) array->data;

				if (
					ft_str_cmp(str_arr[0], string)
					|| ft_str_cmp(str_arr[999], string)
					|| array->length != 1000
					)
					log_test(1)
			}
//			ft_array_func(array, ft_array_func_print$str, NULL);
			ft_array_free(&array);
		}


	// test 1000 nb and add at
	{
		t_array *array = ft_array_init(1, sizeof(int));

		// test if I add 1000 number
		{
			for (int i = 0; i < 1000; ++i)
			{
				ft_array_add_at(&array, &i, i);
			}
			// I assign now because the array is variable
			int *int_arr = (void *) array->data;

			if (
				int_arr[0] != 0
				|| int_arr[999] != 999
				|| array->length != 1000
				)
				log_test(0)
		}
		ft_array_free(&array);
	}


	// test with 10 000 random add in a array of 1000
	// and compare with a classique array
	{
		t_array *array = ft_array_init(1000, sizeof(int));
		int real_array[1000] = { 0 };
		int random_int;

		for (int i = 0; i < 10000; ++i)
		{
			random_int = rand() % 999 + 1;
			ft_array_add_at(&array, &i, random_int);
			real_array[random_int] = i;
		}
	}
}