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

#ifndef LIBFT_LIBFT_TEST_H
#define LIBFT_LIBFT_TEST_H

extern int g_test;
int g_test;

extern char g_test_buffer[100000];
char g_test_buffer[100000];

int lib_cmp_testbuff_log(char *expected);
void lib_clear_testbuff(void);
int ft_test_if_streq(char *res, char *test, char *where);

#endif
