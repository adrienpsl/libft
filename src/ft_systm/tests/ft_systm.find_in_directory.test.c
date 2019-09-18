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

typedef struct s
{
	// logger
	int nb_test;
	int nb_line;

	// function arguments
	char *paths_str;
	char *separators;
	char *binary_name;
	int (*testing_function)(char *, char *);

	// system call
	char *system_setup;
	char *system_cleanup;

	// expected results
	char *expected_str;
} t;

void static test_function(t t)
{
	// Setup
	system(t.system_setup ? t.system_setup : "");
	// Variables
	char *returned_char;

	// Run
	returned_char = ftsystm__find_in_path(
		t.paths_str,
		t.separators,
		t.binary_name,
		t.testing_function);

	// Tests
	if (test_cmp_str(t.expected_str, returned_char))
		log_test_line(t.nb_test, t.nb_line)

	ftstr__free(&returned_char);

	// Cleanup
	system(t.system_cleanup ? t.system_cleanup : "");
}

void test_ftsystm__find_in_path(void)
{

	//	/*
	//	* Path is empty
	//	* */
	//	test_function((t){
	//		// Logger
	//		.nb_test = 0,
	//		.nb_line = L,
	//
	//		// Arguments
	//		.paths_str = "",
	//		.separators = ":",
	//		.binary_name = "file",
	//		.testing_function = ftstr__search_start_strict,
	//
	//		// Expected
	//		.expected_str = NULL
	//	});
	//
	//	/*
	//	* Directories in path do not exist
	//	* */
	//	test_function((t){
	//		// Logger
	//		.nb_test = 1,
	//		.nb_line = L,
	//
	//		// Arguments
	//		.paths_str = "super:mechant:vilain",
	//		.separators = ":",
	//		.binary_name = "file",
	//		.testing_function = ftstr__search_start_strict,
	//
	//		// Expected
	//		.expected_str = NULL
	//	});

	/*
	* Two directories but file doesn't exist
	* */
	{
		test_function((t){
			// Logger
			.nb_test = 2,
			.nb_line = L,

			// Arguments
			.paths_str = "/Users/adpusel/code/42/libft/cmake-build-debug"
						 ":/Users/adpusel/code/42/libft",
			.separators = ":",
			.binary_name = "file",
			.testing_function = ftstr__search_start_strict,

			// Expected
			.expected_str = NULL
		});
	}

	/*
	* The file is in the second one
	* */
	{
		test_function((t){
			// Logger
			.nb_test = 2,
			.nb_line = L,

			// Arguments
			.paths_str = "/Users/adpusel/code/42/libft/cmake-build-debug/ftsystm__find_in_directory_1"
						":/Users/adpusel/code/42/libft/cmake-build-debug/ftsystm__find_in_directory_2",

			.separators = ":",
			.binary_name = "file_d2_99",
			.testing_function = ftstr__search_start_strict,

			// System call
			.system_setup = "mkdir  ftsystm__find_in_directory_1"
							"; touch ftsystm__find_in_directory_1/file_{1..100}"
							"; mkdir ftsystm__find_in_directory_2"
							"; touch ftsystm__find_in_directory_2/file_d2_{1..100}",
			.system_cleanup = "rm -rf ftsystm__find_in_directory_*",

			// Expected
			.expected_str = "file_d2_99"
		});
	}
}