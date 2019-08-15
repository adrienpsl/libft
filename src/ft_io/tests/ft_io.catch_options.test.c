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
#include <ft_printf.h>
#include <ft_io.h>
#include <ft_strsplit.h>

void usage(char c)
{
	static char b[2] = { 0 };

	b[0] = c;
	ft_printf("usage : %s \n", b);
}

void test_ft_io$catch_option()
{
	/*
	* test error handling
	* */
	{
		g_test = 1;
		char *option_str = "a....bcd";
		long options = 0;
		int ret;

		// test no av
		{
			ret = ft_io$catch_option(NULL, option_str, &options, usage);
			if (
				ret != -1
				||
				lib_cmp_testbuff_log(
					"ft_io$catch_options error: array av (null)\n")
				)
				log_test(1)
		}

		// test no option_str
		{
			ret = ft_io$catch_option((char **)"", NULL, &options, usage);
			if (
				ret != -1
				|| lib_cmp_testbuff_log(
					"ft_io$catch_options error: str / ptr ptr (null)\n")
				)
				log_test(1)
		}

		// test no options_ptr
		{
			ret = ft_io$catch_option((char **)"", "", NULL, usage);
			if (
				ret != -1
				|| lib_cmp_testbuff_log(
					"ft_io$catch_options error: str / ptr ptr (null)\n")
				)
				log_test(1)
		}

		// test no function
		{
			ret = ft_io$catch_option((char **)"", "NULL", &options, NULL);
			if (
				ret != -1
				||
				lib_cmp_testbuff_log(
					"ft_io$catch_options error: func ptr (null)\n")
				)
				log_test(1)
		}
		g_test = 0;
	}

	/*
	* test good input
	* */
	{
		char *option_str = "1....5678";
		long options = 0;
		int ret;

		// test catch simple option
		{
			char **split = ft_strsplit("-1", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 1
				|| options != 1
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test catch two simple
		{
			char **split = ft_strsplit("-1 -5", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 2
				|| options != (1 | (1 << 5))
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test catch two simple
		{
			char **split = ft_strsplit("-15", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 1
				|| options != (1 | (1 << 5))
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test catch two simple
		{
			char **split = ft_strsplit("-15 -16", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 2
				|| options != (1 | (1 << 5) | (1 << 6))
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test catch two simple
		{
			char **split = ft_strsplit("-15 -16 -777778", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 3
				|| options != (1 | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8))
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test stop options after option
		{
			char **split = ft_strsplit("-15 -- 16 -777778", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 2
				|| options != (1 | (1 << 5))
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test stop options  option
		{
			char **split = ft_strsplit("-- 15 -- 16 -777778", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 1
				|| options != 0
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test stop options  option
		{
			char **split = ft_strsplit("-- 15 -- 16 -777778", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 1
				|| options != 0
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

		// test triple ifemme
		{
			char **split = ft_strsplit("--- 15 -- 16 -777778", " ");
			options = 0;

			g_test = 1;
			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != -1
				|| options != 0
				|| lib_cmp_testbuff("usage : - \n")
				)
				log_test(1)

			g_test = 0;
			ft_strsplit_free(&split);
		}


		// test triple ifemme
		{
			char **split = ft_strsplit("-hsn 15 -- 16 -777778", " ");
			options = 0;

			g_test = 1;
			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != -1
				|| options != 0
				|| lib_cmp_testbuff("usage : h \n")
				)
				log_test(1)

			g_test = 0;
			ft_strsplit_free(&split);
		}


		// test triple ifemme
		{
			char **split = ft_strsplit("-- 15 -- 16 -777778", " ");
			options = 0;

			ret = ft_io$catch_option(split, option_str, &options, usage);
			if (
				ret != 1
				|| options != 0
				)
				log_test(1)

			ft_strsplit_free(&split);
		}

	}



}