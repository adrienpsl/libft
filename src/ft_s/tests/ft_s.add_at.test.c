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
#include "libft.h"

typedef struct s
{
	int nb_test;
	int nb_line;

	char *start_string;
	char *adding_string;
	int index;

	char *result_buffer;
	int result_int;
} t;

void static test_function(t t)
{
	g_test = 1;
	t_s *s = fts__init(0);
	fts__add(s, t.start_string);

	int ret = fts__add_at(s, t.adding_string, t.index);

	if (test_cmp_int(t.result_int, ret))
		log_test_line(t.nb_test, t.nb_line)
	if (test_cmp_str(t.result_buffer, s->data))
		log_test_line(t.nb_test, t.nb_line);

	fts__free(&s);
	g_test = 0;
}
void test_fts__add_at(void);
void test_fts__add_at(void)
{
	/*
	* Error test
	* */
	{
		g_test = 1;

		// test s null
		fts__add_at(NULL, NULL, 0);
		if (test_cmp_testbuff_log("fts__add_at error: s ptr (null)\n"))
			log_test_line(1, L)

		// test str null
		fts__add_at((t_s *)1, NULL, 0);
		if (test_cmp_testbuff_log("fts__add_at error: str ptr (null)\n"))
			log_test_line(1, L)

		// test index bigger
		t_s *s = fts__init(10);

		fts__add_at(s, "sup", 100);
		if (test_cmp_testbuff_log(
			"fts__add_at error: index bigger than length\n"))
			log_test_line(1, L)

		fts__free(&s);
		g_test = 0;
	}

	/*
	* Normal test
	* */
	{
		// add to nothing
		test_function((t){ 0, L,
						   "super", "", 0,
						   "super", OK });
		// add to start
		test_function((t){ 0, L,
						   "super", "hey ", 0,
						   "hey super", OK });


		// add to end
		test_function((t){ 0, L,
						   "super", " forte", 5,
						   "super forte", OK });

		// add to middle
		test_function((t){ 0, L,
						   "super minh", " forte", 5,
						   "super forte minh", OK });

	}
}