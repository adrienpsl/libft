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
#include "ft_array.test.h"

void test_ft_array_init()
{
	t_array *array = ft_array_init(10, sizeof(int));

	if (array->capacity != (10 * 2) - 3 ||
		array->element_size != sizeof(int))
	{
//		printf("error test : %d \n", );
	}
	ft_array_free(&array);
//	if (array)
//		printf("error test : %d at free \n", test.test_nb);
}
