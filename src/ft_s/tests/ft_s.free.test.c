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
#include <ft_s.h>
#include <ft_test.h>

void test_fts__free()
{
	/*
	* test error handling
	* */
	{
		t_s *s = NULL;

		g_test = 1;
		test_clear_testbuff();

		fts__free(NULL);
		if (
			test_cmp_testbuff_log("fts__free error: s ptr (null)\n")
			)
			log_test(0)

		fts__free(&s);
		if (
			s
			|| test_cmp_testbuff_log("fts__free error: s ptr (null)\n")
			)
			log_test(1)

		g_test = 0;
	}

	/*
	* test good input
	* */
	{
		t_s *s = fts__init(0);
		fts__add(s, "1234567890");

		fts__free(&s);
		if (
			s
			)
			log_test(2)
	}
}