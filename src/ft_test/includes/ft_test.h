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

#ifndef LIBFT_FT_TEST_H
#define LIBFT_FT_TEST_H

# include "stdio.h"
#define log_test(test_nb) printf("log : %s:%d: test: %d\n", __FILE__, __LINE__, test_nb);

extern int g_test;
int g_test;

extern char g_test_buffer[100000];
char g_test_buffer[100000];

int test_random_int(int limit);
void test_print_func_int(void *ptr);

void test_clear_testbuff(void);
int test_cmp_testbuff_log(char *expected);
int test_cmp_testbuff(char *expected);

int ft_test_if_streq(char *res, char *test, char *where);

#endif
