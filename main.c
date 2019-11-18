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

#include <ft_log.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "log.h"

void test_ft_array_main(void);
void test_ft_s_main(void);
void test_ft_iocatch_option(void);
void test_main_ft_pf(void);
void test_main_ft_buffer(void);
void test_ftstr_main(void);
void test_ftsystm_main(void);

static void test()
{
	//	if (test_ft_memory())
	//		printf("error memory \n");
	//	if (test_ft_list())
	//		printf("error list \n");
	//	test_ft_str();
	//	test_ft_char();
	//	test_ft_buffer();
	//	test_ft_array();
	//	test_ft_io();
	//		if (test_ft_printf())
	//		printf("printf error\n");
	//	test_ft_array_main();
	//	test_ft_s_main();
	//	test_ft_iocatch_option();
	//	test_main_ft_buffer();
	//	test_main_ft_pf();
	//	test_ftstr_main();
//	test_ftsystm_main();
}

void log_log(int level, const char *file, int line, const char *fmt, ...);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//	g_test = 1;
	g_log = TRACE;
	test();
	size_t t = 21312318889;
	ft_printf("%p - %p %lu", t, t, t);


	return (EXIT_SUCCESS);
}







