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

void print_int(int x)
{
	for (int i = sizeof(x) << 3; i; i--)
		putchar('0' + ((x >> (i - 1)) & 1));
	printf(" \n");
}

void print_long(long x)
{
	for (int i = sizeof(x) << 3; i; i--)
		putchar('0' + ((x >> (i - 1)) & 1));
}

void utils(t_pf *pf, ...)
{
	intmax_t nb;

	va_start(pf->list, pf);
	nb = va_arg(pf->list, int);
//	print_long(nb);
	printf("\n%ld", nb);
	printf("\n%ld\n", (unsigned)nb);
	//	ft_pf_get_variable(pf);
	va_end(pf->list);
}

void test_ft_pf_get_variable()
{
	t_pf pf;

	ft_bzero(&pf, sizeof(t_pf));

	utils(&pf, SHRT_MIN);
	utils(&pf, SHRT_MAX);
	utils(&pf, UINT_MAX);
	utils(&pf, INT_MAX);
	utils(&pf, INT_MIN);
	utils(&pf, -1);



	//	pf.format_bit.little = 1;
	//	utils(&pf, SHRT_MIN);
	//	utils(&pf, INT_MIN);
}
