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
#include <ft_s.h>
#include <ft_mem.h>

void	test_fts__clear()
{
	/*
	* test error handling
	* */
	{
		int ret;
		g_test = 1;
		test_clear_testbuff();

		ret = fts__clear(NULL);
		if (
			!ret
			|| test_cmp_testbuff_log("ft_s$clear error: s ptr (null)\n")
			)
			log_test(0)

		g_test = 0;
	}

	/*
	* test good input
	* */
	{
		t_s *s = fts__init(0);
		char *test = ft_memalloc(1000);
		fts__add(s, "1234567890");

		fts__clear(s);
		if (
			s->length
			|| ft_memcmp(test, s->data, s->capacity)
			)
			log_test(1)
	}
}