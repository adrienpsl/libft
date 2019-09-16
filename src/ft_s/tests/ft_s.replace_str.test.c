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

#include <ft_s.h>
#include <ft_test.h>
#include <ft_log.h>
#include <libft_define.h>

typedef struct s
{
	int nb_test;
	int nb_line;

	char *start_str;
	char *wanted_str;
	char *substitute_str;

	char *result_str;
	int result_int;
} t;

static void func_test(t t)
{
	g_test = 1;
	t_s *s;

	s = fts__init(100);
	fts__add(s, t.start_str);

	int ret = fts__replace_str(s, t.wanted_str, t.substitute_str);

	if (test_cmp_int(t.result_int, ret))
		log_test_line(t.nb_test, t.nb_line)

	if (test_cmp_str(t.result_str, s->data))
		log_test_line(t.nb_test, t.nb_line)

	fts__free(&s);
	g_test = 0;
}

void	test_fts__replace_str()
{
	// no data at all
	func_test((t){ 0, L,
				   "", "", "",
				   "", -1,
	});

	// search nothing
	func_test((t){ 0, L,
				   "toto", "", "",
				   "toto", -1,
	});

	// nothing
	func_test((t){ 1, L,
				   "", "toto", "",
				   "", -1,
	});

	// one element
	func_test((t){ 2, L,
				   "toto", "toto", "",
				   "", OK,
	});

	// one element
	func_test((t){ 3, L,
				   "to--toto", "toto", "",
				   "to--", OK,
	});

	func_test((t){ 3, L,
				   "to--totototo", "toto", "",
				   "to--toto", OK,
	});

	func_test((t){ 3, L,
				   "to--totototo", "toto", "ti",
				   "to--titoto", OK,
	});

	func_test((t){ 3, L,
				   "to--totototo", "toto", "titititi",
				   "to--tititititoto", OK,
	});

	func_test((t){ 5, L,
				   "12345", "23", "23",
				   "12345", OK,
	});
}
