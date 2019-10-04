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
	pf__get_str(pf);
	va_end(pf->list);
}

void	test_pf__get_str(void)
{
	t_pf pf;

	// str test
	utils(&pf, "%sd", "toto");
	if (0 != ft_strcmp("toto", pf.intern_str))
		log_test(0)

	// char test
	utils(&pf, "%cd", 'c');
	if (0 != ft_strcmp("c", pf.intern_str))
		log_test(0)

	utils(&pf, "%cd", '\t');
	if (0 != ft_strcmp("\t", pf.intern_str))
		log_test(0)
}
