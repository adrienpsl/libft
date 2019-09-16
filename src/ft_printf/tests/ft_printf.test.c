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

#include <ft_test.h>
#include <ft_test.h>
#include "libft.h"

void	test_ft_printf()
{
	g_test = 1;
	test_clear_testbuff();

	// error test
	{
		ft_printf("toto");
		if (test_cmp_testbuff("toto"))
			log_test(1)

		ft_printf("toto%");
		if (test_cmp_testbuff("toto"))
			log_test(1)

		ft_printf("toto%%");
		if (test_cmp_testbuff("toto%"))
			log_test(1)

		ft_printf("to%to");
		if (test_cmp_testbuff("toto"))
			log_test(1)

		ft_printf("");
		if (test_cmp_testbuff(""))
			log_test(1)

		ft_printf("%%%%%");
		if (test_cmp_testbuff("%%"))
			log_test(1)
	}

	// single arr test
	{
		ft_printf("%d", 22);
		if (test_cmp_testbuff("22"))
			log_test(1)

		ft_printf("%%%d", 22);
		if (test_cmp_testbuff("%22"))
			log_test(1)

		ft_printf("%ld", (long)-1);
		if (test_cmp_testbuff("-1"))
			log_test(1)

		ft_printf("%22s", "12");
		if (test_cmp_testbuff("                    12"))
			log_test(1)
	}

	// test with two format
	{
		ft_printf("%d  %h10b", 22, 42);
		if (test_cmp_testbuff("22      101010"))
			log_test(1)

		ft_printf("%%%d %022-s", 22, "toto");
		if (test_cmp_testbuff("%22 toto000000000000000000"))
			log_test(1)

		ft_printf("%ld %d %hd ", (long)-1, -1, -1);
		if (test_cmp_testbuff("-1 -1 -1 "))
			log_test(1)

		ft_printf("%22s", "12");
		if (test_cmp_testbuff("                    12"))
			log_test(1)

		ft_printf("0x  %010x", 42);
		if (test_cmp_testbuff("0x  000000002a"))
			log_test(1)
	}

	g_test = 0;
}
