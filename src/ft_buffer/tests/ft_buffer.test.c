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
#include "libft.h"

void	test_ft_buffer()
{

	t_buffer buffer;
	char *a = "c";
	char str[2000] = { 0 };


	// test add 1022 char
	{
		ft_bzero(&buffer, sizeof(t_buffer));
		for (int i = 0; i < 1022; ++i)
		{
			ft_buffer_add(&buffer, a, 1);
			str[i] = 'c';
		}
		if (
			ft_strlen(buffer.data) != 1022
			|| buffer.length != 1022
			|| ft_str_cmp(str, buffer.data))
			log_test(1)
	}

	// test if print and reset
	{
		g_test = 1;
		test_clear_testbuff();

		char clear[2000] = "et voila encore du texte putain";
		ft_buffer_add(&buffer, clear, ft_strlen(clear));

		str[1023] = 'c';
		if (
			ft_str_cmp(g_test_buffer, str)
			|| buffer.length != (int)ft_strlen(clear)
			|| ft_memcmp(clear, buffer.data, 1024)
			)
			log_test(2)

		g_test = 0;
	}
}
