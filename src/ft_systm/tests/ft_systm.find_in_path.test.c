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

#include <ft_systm.h>
#include <stdlib.h>
#include <ft_test.h>

void test_ftsystm__find_in_directory(void)
{
	/*
	* There is no directory
	* */
	{
		// Variables
		char *returned_char;

		returned_char = ftsystm__find_in_directory(
			"nothing", "search", ftstr__search_start);
		if (test_cmp_str(NULL, returned_char))
			log_test(0)
	}

	/*
	* the file ins't is the directory
	* */
	{
		// Setup
		system("mkdir -p ftsystm__find_in_directory_test");
		system("touch ftsystm__find_in_directory_test/file_{1..20}");

		// Variables
		char *returned_char;

		// Run
		returned_char = ftsystm__find_in_directory(
			"ftsystm__find_in_directory_test",
			"file",
			ftstr__search_start_strict
		);

		// Tests
		if (test_cmp_str(NULL, returned_char))
			log_test(1)

		// Cleanup
		system("rm -rf ftsystm__find_in_directory_test");
	}

	/*
	* the file is in directory
	* */
	{
		// Setup
		system("mkdir -p ftsystm__find_in_directory_test");
		system("touch ftsystm__find_in_directory_test/file_{1..20}");


		// Variables
		char *returned_char;

		// Run
		returned_char = ftsystm__find_in_directory(
			"ftsystm__find_in_directory_test",
			"file_2",
			ftstr__search_start_strict
		);

		// Tests
		if (test_cmp_str("file_2", returned_char))
			log_test(3)

		// Cleanup
		system("rm -rf ftsystm__find_in_directory_test");
	}


}
