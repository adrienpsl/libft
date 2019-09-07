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

#include <libft.test.h>
#include <test.h>
#include "libft.h"

void test_ftstr__search_start()
{

	/*
	* test bad entry
	* */
	{
		g_test = 1;
		test_clear_testbuff();
		// test null entry
		{
			int res;
			res = ftstr__search_start(NULL, "toto", NULL);
			if (
				res != -1 ||
				test_cmp_testbuff_log("ftstr__search_start input (null)\n")
				)
				log_test(0)

			res = ftstr__search_start("toto", NULL, NULL);
			if (
				res != -1 ||
				test_cmp_testbuff_log("ftstr__search_start input (null)\n")
				)
				log_test(0)
		}
	}

	/*
	* test strict
	* */
	{
		// test strict nothing common
		{
			int param = FTSTR__SEARCH_START_STRICT;
			int res = ftstr__search_start("toto", "faire des chipes", &param);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict middle
		{
			int param = FTSTR__SEARCH_START_STRICT;
			int res = ftstr__search_start("toto", "faire toto des chipes",
										  &param);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict middle
		{
			int param = FTSTR__SEARCH_START_STRICT;
			int res = ftstr__search_start("toto", "faire toto des chipes",
										  &param);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict middle
		{
			int param = FTSTR__SEARCH_START_STRICT;
			int res = ftstr__search_start("toto", "totot", &param);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict good
		{
			int param = FTSTR__SEARCH_START_STRICT;
			int res = ftstr__search_start("toto", "toto", &param);
			if (
				res != 4 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}
	}

	/*
	* test partial
	* */
	{
		// test partial nothing
		{
			int param = FTSTR__SEARCH_START_PARTIAL;
			int res = ftstr__search_start("toto", "aouaeou aoeu toto", &param);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(3)
		}

		// test partial start
		{
			int param = FTSTR__SEARCH_START_PARTIAL;
			int res = ftstr__search_start("toto", "tototototototo", &param);
			if (
				res != 4 ||
				test_cmp_testbuff_log("")
				)
				log_test(3)
		}
		// test partial start
		{
			int param = FTSTR__SEARCH_START_PARTIAL;
			int res = ftstr__search_start("t", "tototototototo", &param);
			if (
				res != 1 ||
				test_cmp_testbuff_log("")
				)
				log_test(3)
		}
	}
}
