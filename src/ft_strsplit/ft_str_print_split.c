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

void	ft_strsplit_print_test(char **p_str)
{
	if (!p_str)
		return ;
	while (*p_str)
	{
		ft_printf("-%s-\n", *p_str);
		p_str++;
	}
}

void	ft_strsplit_print(char **p_str, char sep)
{
	static char sep_str[2] = { 0, 0 };

	if (NULL == p_str)
		return ;
	sep_str[0] = sep;
	while (NULL != *p_str)
	{
		ft_printf("%s", *p_str);
		if (*(p_str + 1))
			ft_printf("%s", sep_str);
		p_str++;
	}
}
