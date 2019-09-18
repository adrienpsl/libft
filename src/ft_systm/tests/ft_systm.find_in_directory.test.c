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
#include <ft_test.h>
#include <stdlib.h>

void test_ftsystm__find_in_path(void)
{
	/*
	* the file ins't is the directory
	* */
	{
		// Setup
		system("mkdir -p ftsystm__find_in_directory_test");
		chdir("ftsystm__find_in_directory_test");
		system("touch file_{1..20}");
		chdir("..");

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

	// test with no path

	// test with bad directory
}