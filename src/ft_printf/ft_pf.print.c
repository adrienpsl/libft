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

size_t padding_calculation(t_pf *pf)
{
	size_t length;

	{
		length = ft_strlen(pf->intern_str);
		pf->format_bit.padding -= length;
	}
	if (
		pf->format_bit.padding < 0
		)
		pf->format_bit.padding = 0;
	return (length);
}

static void print(t_pf *pf, char *data, int size)
{
	if (pf->extern_buff)
		ft_strcat(pf->extern_buff, data);
	else
	{
		ft_buffer_add(&pf->buff, data, size);
	}
}

void add_padding(t_pf *pf)
{
	static char buff[2] = { 0 };

	buff[0] = pf->format_bit.zero ? '0' : ' ';
	while (pf->format_bit.padding)
	{
		print(pf, buff, 1);
		pf->format_bit.padding -= 1;
	}
}

int pf$print(t_pf *pf)
{
	size_t length;

	length = padding_calculation(pf);
	if (
		0 == pf->format_bit.minus
		)
		add_padding(pf);
	print(pf, pf->intern_str, length);
	if (
		1 == pf->format_bit.minus
		)
		add_padding(pf);
	return (0);
}
