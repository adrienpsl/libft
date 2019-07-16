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

#include "libft.h"

void ft_test_clear_testbuff()
{
	ft_bzero(g_test_buffer, 10000);
}

void ft_test_ifcmp_printsplit(char **res, char **test)
{
	if (ft_str_split_cmp(res, test))
	{
		g_test = 0;
		ft_printf("=============  split  error =====================\n");
		ft_printf("--- result ---\n");
		ft_strsplitprint_test(res);
		ft_printf("--- test ---\n");
		ft_strsplitprint_test(test);
		g_test = 1;
	}
}

void ft_test_if_streq(char *res, char *test)
{
	if (!ft_test_streq(res, test))
	{
		g_test = 0;
		ft_printf("============== str error ================\n");
		ft_printf("--- result ---\n");
		ft_printf("%s \n", res);
		ft_printf("--- test ---\n");
		ft_printf("%s \n", test);
		g_test = 1;
	}
}