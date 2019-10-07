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


static int					utils(char *format, char *result, ...)
{
	int ret = 0;
	t_pf p;
	t_pf *pf = &p;

	ft_bzero(pf, sizeof(t_pf));
	pf->format = format;
	pf__catch_format(pf);

	va_start(pf->list, result);
	pf__get_str(pf);
	pf__get_number(pf);
	va_end(pf->list);

	pf__print(pf);
	if (ft_strcmp(pf->buff.data, result))
	{
		printf("-%s-\n", result);
		printf("-%s-\n", pf->buff.data);
		ret = (1);
	}

	return (ret);
}

void	test_pf$print(void);
void	test_pf$print(void)
{
	// test padding right
	if (utils("%10d", "        22", 22))
		log_test(1)

	// test padding left
	if (utils("%-10d", "22        ", 22))
		log_test(1)

	// test padding little than number
	if (utils("%-5d", "12345678", 12345678))
		log_test(1)

	// test padding little than number
	if (utils("%-010x", "bc614e0000", 12345678))
		log_test(1)

	if (utils("%010x", "0000bc614e", 12345678))
		log_test(1)

	// test with 0 and padding
	if (utils("%010b", "0000101010", 42))
		log_test(1)

	// test with str
	if (utils("%010s", "0012345678", "12345678"))
		log_test(1)

	// test with char
	if (utils("%1c", "a", 'a'))
		log_test(1)
}
