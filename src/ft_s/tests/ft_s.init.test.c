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
#include <test.h>
#include <ft_mem.h>
#include <ft_str.h>
#include "libft.h"

void test_ft_s$init()
{
	/*
	* test good input
	* */
	{
		// test with 0
		{
			t_s *s = ft_s$init(0);
			char *test = ft_memalloc(1000);

			if (
				s->i != 0
				|| s->capacity != 2
				|| s->data != (char *)s + sizeof(t_s)
				|| ft_memcmp(s->data, test, 2)
				)
				log_test(0)

			ft_s$free(&s);
		}

		// test with 42
		{
			t_s *s = ft_s$init(42);
			char *test = ft_memalloc(1000);

			if (
				s->i != 0
				|| s->capacity != 84
				|| s->data != (char*)s + sizeof(t_s)
				|| ft_memcmp(s->data, test, 42)
				)
				log_test(1)
		}
	}
}
