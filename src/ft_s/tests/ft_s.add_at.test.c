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

	char *result_str;
	char *result_print;
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
	if (test_cmp_str(t.result_str, s->data))
		log_test_line(t.nb_test, t.nb_line);
	if (test_cmp_testbuff_log(t.result_print))
		log_test_line(t.nb_test, t.nb_line);

	fts__free(&s);
	g_test = 0;
}

void test_fts__add_at()
{
	/*
	* Error test
	* */
	{
		faire les test pour les errer en dur ici
		// test null s
		test_function((t){ 0, L,
						   "", "", 10,
						   "", "fts__add_at error: index bigger than length\n",
						   -1 });

		// test index bigger
		test_function((t){ 0, L,
						   "", "", 10,
						   "", "fts__add_at error: index bigger than length\n",
						   -1 });
	}

	/*
	* Normal test
	* */
	{
		// test add nothigth

		// test
	}
}