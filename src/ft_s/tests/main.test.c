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
#include <ft_printf.h>

/* ************************************************************************** */

void test_fts__init();
void test_fts__add();
void test_fts__free();
void test_fts__clear();
void test_fts__remove_from();
void test_fts__replace_str();


void test_ft_s_main(void)
{
	test_fts__init();
	test_fts__add();
	test_fts__free();
	test_fts__clear();
	test_fts__remove_from();
	test_fts__replace_str();
}