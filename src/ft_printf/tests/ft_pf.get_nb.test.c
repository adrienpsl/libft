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
#include "ft_pf.main.test.h"

static void			utils(t_pf *pf, char *format, ...)
{
	ft_bzero(pf, sizeof(t_pf));
	pf->format = format;
	pf__catch_format(pf);

	va_start(pf->list, format);
	pf__get_number(pf);
	va_end(pf->list);
}

void	test_ft_pf__get_nb(void)
{
	t_pf pf;

	// short test
	{
		utils(&pf, "hd", SHRT_MIN);
		if (0 != ft_strcmp("-32768", pf.intern_str))
			log_test(0)

		utils(&pf, "hd", SHRT_MAX);
		if (0 != ft_strcmp("32767", pf.intern_str))
			log_test(1)

		utils(&pf, "hu", USHRT_MAX);
		if (0 != ft_strcmp("65535", pf.intern_str))
			log_test(2)

		utils(&pf, "hu", 0);
		if (0 != ft_strcmp("0", pf.intern_str))
			log_test(3)

		utils(&pf, "hu", 10);
		if (0 != ft_strcmp("10", pf.intern_str))
			log_test(3)
	}

	// int test
	{
		utils(&pf, "%d", INT_MAX);
		if (0 != ft_strcmp("2147483647", pf.intern_str))
			log_test(3)

		utils(&pf, "%d", INT_MIN);
		if (0 != ft_strcmp("-2147483648", pf.intern_str))
			log_test(3)

		utils(&pf, "%u", UINT_MAX);
		if (0 != ft_strcmp("4294967295", pf.intern_str))
			log_test(3)

		utils(&pf, "%d", 0);
		if (0 != ft_strcmp("0", pf.intern_str))
			log_test(3)

		utils(&pf, "%du", 10);
		if (0 != ft_strcmp("10", pf.intern_str))
			log_test(3)

		utils(&pf, "%d", -1);
		if (0 != ft_strcmp("-1", pf.intern_str))
			log_test(3)
	}

	// long test
	{
		utils(&pf, "%ld", LONG_MAX);
		if (0 != ft_strcmp("9223372036854775807", pf.intern_str))
			log_test(3)

		utils(&pf, "%ld", LONG_MIN);
		if (0 != ft_strcmp("-9223372036854775808", pf.intern_str))
			log_test(3)

		utils(&pf, "%lu", ULONG_MAX);
		if (0 != ft_strcmp("18446744073709551615", pf.intern_str))
			log_test(3)
	}

	// test long with binaire,
	{
		utils(&pf, "%b", LONG_MAX);
		if (0 != ft_strcmp("11111111111111111111111111111111", pf.intern_str))
			log_test(3)

		utils(&pf, "%lb", LONG_MIN);
		if (0 != ft_strcmp(
			"1000000000000000000000000000000000000000000000000000000000000000",
			pf.intern_str))
			log_test(3)

		utils(&pf, "%hb", ULONG_MAX);
		if (0 != ft_strcmp("1111111111111111", pf.intern_str))
			log_test(3)

		utils(&pf, "%lb", 0);
		if (0 != ft_strcmp("0", pf.intern_str))
			log_test(3)
	}

	// test with hexa
	{
		utils(&pf, "%hx", LONG_MAX);
		if (0 != ft_strcmp("ffff", pf.intern_str))
			log_test(3)

		utils(&pf, "%lx", LONG_MAX);
		if (0 != ft_strcmp(
			"7fffffffffffffff",
			pf.intern_str))
			log_test(3)

		utils(&pf, "%x", ULONG_MAX);
		if (0 != ft_strcmp("ffffffff", pf.intern_str))
			log_test(3)
	}
}
