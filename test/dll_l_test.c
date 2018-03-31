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

#include "../sources/ft_library_header.h"

t_dll_l link_test;

void init()
{
}

void destroy()
{
	destroy_dll_l(&link_test);
}

static void test__1_() // test destroy et construct sur content vide
{
	char *str = "test 1 \n test de test destroy et construct sur content vide";
	(void) str;

	link_test = new_dll_l(NULL, 0);
	destroy();
}

static void test__2_() // en mettant des data dans mon link
{
	init();

	char *str = "test 2 \n test de en mettant des data dans mon link";
	(void) str;
	link_test = new_dll_l(str, ft_strlen(str));
	destroy();
}

void all_test_dll_l()
{
	test__1_();
	test__2_();
}

//int main()
//{
//	all_test_dll_l();
//	return (0);
//}