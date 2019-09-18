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
#include "libft.h"

void	test_ft_pf_catch_format()
{
	t_pf pf;
	int ret;

	// test end str
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%";
		ret = pf__catch_format(&pf);
		if (
			ret != -1
			|| *pf.format
			|| *(int *)&pf.format_bit
			|| pf.format_bit.padding
			)
			log_test(0)
	}

	// no element
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%toto";
		ret = pf__catch_format(&pf);
		if (
			ret != -1
			|| ft_strcmp("toto", pf.format)
			|| *(int *)&pf.format_bit
			|| pf.format_bit.padding
			)
			log_test(1)
	}

	// test just first
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%-";
		ret = pf__catch_format(&pf);
		if (
			ret != -1
			|| ft_strcmp("", pf.format)
			|| *(int *)&pf.format_bit != (1)
			|| pf.format_bit.padding
			)
			log_test(2)
	}


	// test just first two
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%0";
		ret = pf__catch_format(&pf);
		if (
			ret != -1
			|| ft_strcmp("", pf.format)
			|| *(int *)&pf.format_bit != 1 << 3
			|| pf.format_bit.padding
			)
			log_test(3)
	}

	// test first all option
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%0....-000******--toto";
		ret = pf__catch_format(&pf);
		if (
			ret != -1
			|| ft_strcmp("toto", pf.format)
			|| *(int *)&pf.format_bit != (15)
			|| pf.format_bit.padding
			)
			log_test(4)
	}

	// test first second all format
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%lllllhhlhlhhhllhhllhtoto";
		ret = pf__catch_format(&pf);
		if (
			ret != -1
			|| ft_strcmp("toto", pf.format)
			|| *(int *)&pf.format_bit != (48)
			|| pf.format_bit.padding
			)
			log_test(5)
	}

	// test only first cast
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%stoto";
		ret = pf__catch_format(&pf);
		if (
			ret != 0
			|| ft_strcmp("toto", pf.format)
			|| *(int *)&pf.format_bit != (64)
			|| pf.format_bit.padding
			)
			log_test(6)
	}

	// test last cast
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%btoto";
		ret = pf__catch_format(&pf);
		if (
			ret != 0
			|| ft_strcmp("toto", pf.format)
			|| *(int *)&pf.format_bit != (1024)
			|| pf.format_bit.padding
			)
			log_test(7)
	}

	// test str mix all and padding mix
	{
		ft_bzero(&pf, sizeof(t_pf));
		pf.format = "%-***-...003200hhhllllhh32bbtoto";
		ret = pf__catch_format(&pf);
		if (
			ret != 0
			|| ft_strcmp("btoto", pf.format)
			|| *(int *)&pf.format_bit != (1087)
			|| pf.format_bit.padding != 32
			)
			log_test(8)
	}
}
