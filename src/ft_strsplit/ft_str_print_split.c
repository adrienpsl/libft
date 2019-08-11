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

#include <ft_printf.h>
#include "libft.h"

void ft_strsplit_print_test(char **p_str)
{
	if (!p_str)
		return;
	while (*p_str)
	{
		ft_printf("-%s-\n", *p_str);
		p_str++;
	}
}

void ft_strsplit_print(char **p_str, char sep)
{
	static char sep_str[2] = { 0, 0 };
	if (!p_str)
		return;
	sep_str[0] = sep;
	while (*p_str)
	{
		ft_printf("%s", *p_str);
		if (*(p_str + 1))
			ft_printf("%s", sep_str);
		p_str++;
	}
}

void ft_print_two_split(char **res, char **test)
{
//	g_test = 0;
	ft_printf("res\n");
	ft_strsplit_print_test(res);
	ft_printf("----------------\n");
	ft_printf("test\n");
	ft_strsplit_print_test(test);
	ft_printf("\n");
//	g_test = 1;
}
