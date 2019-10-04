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
#include <ft_str.h>

void	test_fts__remove_from(void);
void	test_fts__remove_from(void)
{
	/*
	* test bad entry
	* */
	{
		g_test = 1;
		test_clear_testbuff();

		// test : no fs == null
		{
			fts__remove_from(NULL, 10);
			if (
				test_cmp_testbuff_log("fts__remove_from error: s ptr (null)\n")
				)
				log_test(0)
		}

		// test : index sup
		{
			t_s *s = fts__init(10);
			fts__add(s, "0123456789");
			fts__remove_from(s, 10);
			if (
				test_cmp_testbuff_log(
					"fts__remove_from error: start > length\n")
				)
				log_test(0)
		}

		// test : with empty
		{
			t_s *s = fts__init(0);
			fts__remove_from(s, 0);
			if (
				test_cmp_testbuff_log(
					"fts__remove_from error: start > length\n")
				)
				log_test(0)
		}
		g_test = 0;
	}

	/*
	* test good entries
	* */
	{
		// test : by 0
		{
			t_s *s = fts__init(0);
			fts__add(s, "0123456789");
			fts__remove_from(s, 0);
			if (
				ft_strcmp("", s->data)
				)
				log_test(1)
		}

		// test : by length - 1
		{
			t_s *s = fts__init(0);
			fts__add(s, "0123456789");
			fts__remove_from(s, s->length - 1);
			if (
				ft_strcmp("012345678", s->data)
				)
				log_test(1)
		}


		// test : by 5
		{
			t_s *s = fts__init(10);
			fts__add(s, "0123456789");
			fts__remove_from(s, 5);
			if (
				ft_strcmp("01234", s->data)
				)
				log_test(1)
		}
	}
}
