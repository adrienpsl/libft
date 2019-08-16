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

#include <test.h>
#include "libft.h"

 int utils(char *format, char *result, ...)
{
	t_array *array = ft_array$init(2000, 1);
	int ret = 0;
	t_pf p;
	t_pf *pf = &p;

	ft_bzero(pf, sizeof(t_pf));

	pf->format = format;
	pf$catch_format(pf);

	va_start(pf->list, result);
	pf$get_str(pf);
	pf$get_number(pf);
	va_end(pf->list);

	pf$print(pf);
	if (ft_str_cmp(array->data, result))
	{
		printf("-%s-\n", result);
		printf("-%s-\n", array->data);
		ret = (1);
	}
	ft_array$free(&array);

	return (ret);
}

void test_pf$print()
{
	if (utils("10d", "        22", 22))
		log_test(1)
	printf("%22s \n", "toto");
}
