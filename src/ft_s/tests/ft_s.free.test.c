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
#include <ft_s.h>
#include <test.h>

void test_ft_s$free()
{
	/*
	* test error handling
	* */
	{
		t_s *s = NULL;

		g_test = 1;
		lib_clear_testbuff();

		ft_s$free(NULL);
		if (
			lib_cmp_testbuff("ft_s$free error: s ptr (null)\n")
			)
			log_test(0)

		ft_s$free(&s);
		if (
			s
			|| lib_cmp_testbuff("ft_s$free error: s ptr (null)\n")
			)
			log_test(1)

		g_test = 0;
	}

	/*
	* test good input
	* */
	{
		t_s *s = ft_s$init(0);
		ft_s$add(&s, "1234567890");

		ft_s$free(&s);
		if (
			s
			)
			log_test(2)
	}
}