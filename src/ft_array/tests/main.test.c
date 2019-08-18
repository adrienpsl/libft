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

void test_ft_array_init(void);
void test_ft_array$add(void);
void test_ft_array$at(void);
void test_ft_array$bubble(void);
void test_ft_array_next_and_prev(void);
void test_ft_array$cmp();
void test_ft_array$copy();
void test_ft_array_double_size();
void test_ft_array_free();
void test_ft_array$func();
void test_ft_array_remove();
void test_ft_array$utils();
void test_ft_array$cmp();
void test_ft_array$remove_from();
void test_ft_array$slice();
void test_ft_array$slice_and_remove();

void test_ft_array_main(void)
{
	test_ft_array_init();
	test_ft_array$at();
	test_ft_array$add();
	test_ft_array$bubble();
	test_ft_array_next_and_prev();
	test_ft_array$cmp();
	test_ft_array$copy();
	test_ft_array_double_size();
	test_ft_array_free();
	test_ft_array$func();
	test_ft_array_remove();
	test_ft_array$utils();
	test_ft_array$cmp();
	test_ft_array$remove_from();
	test_ft_array$slice();
	test_ft_array$slice_and_remove();
}