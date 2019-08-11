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

#include <stdlib.h>
# include "libft.h"
#include "tests/test.h"

void test()
{
	//	if (test_ft_memory())
	//		printf("error memory \n");
	//	if (test_ft_list())
	//		printf("error list \n");
//	test_ft_str();
//	test_ft_char();
//	test_ft_buffer();
	test_ft_array();
//	test_ft_io();
	//		if (test_ft_printf())
	//		printf("printf error\n");

}

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
//	g_test = 1;
//	g_log_errors = 1;
	test();

	return (EXIT_SUCCESS);
}
