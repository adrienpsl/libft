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

void ft_clear_testbuff()
{
	ft_bzero(g_test_buffer, 10000);
}

void ft_print_splitcmp(char **split_1, char **split_2)
{
	if (ft_str_split_cmp(split_1, split_2))
	{
		g_test = 0;
		ft_printf("split error\n");
		ft_printf("result\n  -- -- --");
		ft_strsplitprint_test(split_1);
		ft_printf("test  \n  -- -- --");
		ft_strsplitprint_test(split_2);
		g_test = 1;
	}
}