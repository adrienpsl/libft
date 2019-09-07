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
			res = ftstr__search_start(NULL, "toto", 0);
			if (
				res != -1 ||
				test_cmp_testbuff_log("ftstr__search_start input (null)\n")
				)
				log_test(0)

			res = ftstr__search_start("toto", NULL, 0);
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
			int res = ftstr__search_start("toto", "faire des chipes",
										  FTSTR__SEARCH_START_STRICT);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict middle
		{
			int res = ftstr__search_start("toto", "faire toto des chipes",
										  FTSTR__SEARCH_START_STRICT);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict middle
		{
			int res = ftstr__search_start("toto", "faire toto des chipes",
										  FTSTR__SEARCH_START_STRICT);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict middle
		{
			int res = ftstr__search_start("toto", "totot",
										  FTSTR__SEARCH_START_STRICT);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(2)
		}

		// test strict good
		{
			int res = ftstr__search_start("toto", "toto",
										  FTSTR__SEARCH_START_STRICT);
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
			int res = ftstr__search_start("toto", "aouaeou aoeu toto", FTSTR__SEARCH_START_PARTIAL);
			if (
				res != -1 ||
				test_cmp_testbuff_log("")
				)
				log_test(3)
		}

		// test partial start
		{
			int res = ftstr__search_start("toto", "tototototototo", FTSTR__SEARCH_START_PARTIAL);
			if (
				res != 4 ||
				test_cmp_testbuff_log("")
				)
				log_test(3)
		}
		// test partial start
		{
			int res = ftstr__search_start("t", "tototototototo", FTSTR__SEARCH_START_PARTIAL);
			if (
				res != 1 ||
				test_cmp_testbuff_log("")
				)
				log_test(3)
		}
	}
}
