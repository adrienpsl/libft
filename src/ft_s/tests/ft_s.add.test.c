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
#include <test.h>
#include <ft_s.h>
#include <ft_str.h>
#include "libft.h"

void test_ft_s$add()
{

	/*
	* test error handling
	* */
	{
		int ret;
		g_test = 1;
		lib_clear_testbuff();

		// test no s
		{
			ret = ft_s$add(NULL, "");
			if (
				!ret
				|| lib_cmp_testbuff_log("ft_s$add error: s ptr (null)\n")
				)
				log_test(0)
		}

		// test no s
		{
			ret = ft_s$add((t_s **)"", NULL);
			if (
				!ret
				|| lib_cmp_testbuff_log("ft_s$add error: str ptr (null)\n")
				)
				log_test(1)
		}

		g_test = 0;
	}

	/*
	* test no error
	* */
	{
		t_s *s = ft_s$init(0);
		int ret;

		// test with no place
		{

			ret = ft_s$add(&s, "12345");
			if (ret
				|| s->capacity != 14
				|| ft_str_cmp("12345", s->data))
				log_test(2)
		}

		// test with big str
		ft_s$clear(s);
		char *str = "asoeuhasoeuhasoeu saoeuh asoehusaoeh u asoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh u vasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh uasoeuhasoeuhasoeu saoeuh asoehusaoeh u";
		ret = ft_s$add(&s, str);
		if (ret
			|| s->capacity != 1630
			|| ft_str_cmp(str, s->data))
			log_test(2)
	}
}
