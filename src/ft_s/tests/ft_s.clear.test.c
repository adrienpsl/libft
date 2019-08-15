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

#include <test.h>
#include <libft.test.h>
#include <ft_s.h>
#include <ft_mem.h>

void test_ft_$clear()
{
	/*
	* test error handling
	* */
	{
		int ret;
		g_test = 1;
		lib_clear_testbuff();

		ret = ft_s$clear(NULL);
		if (
			!ret
			|| lib_cmp_testbuff_log("ft_s$clear error: s ptr (null)\n")
			)
			log_test(0)

		g_test = 0;
	}

	/*
	* test good input
	* */
	{
		t_s *s = ft_s$init(0);
		char *test = ft_memalloc(1000);
		ft_s$add(&s, "1234567890");

		ft_s$clear(s);
		if (
			s->i
			|| ft_memcmp(test, s->data, s->capacity)
			)
		    log_test(1)
	}
}