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
#include <ft_str.h>
#include <ft_mem.h>

void			pf__utils_print(t_pf *pf, char *data, int size)
{
	if (pf->extern_buff)
		ft_memcpy(pf->extern_buff + ft_strlen(pf->extern_buff), data, size);
	else
	{
		ft_buffer_add(&pf->buff, data, size);
	}
}

void			handle_wildcard(t_pf *pf)
{
	if (pf->format_bit.wildard)
		pf->format_bit.padding = va_arg(pf->list, int);
}

void			handle_variable(t_pf *pf)
{
	if (OK == pf__catch_format(pf))
	{
		handle_wildcard(pf);
		pf__get_str(pf);
		pf__get_number(pf);
		pf__print(pf);
	}
	ft_bzero(&pf->format_bit, sizeof(t_pf_format));
	ft_bzero(&pf->char_buffer, 70);
}

void			loop(t_pf *pf)
{
	while (*pf->format)
	{
		if (*pf->format == '%')
			handle_variable(pf);
		else
		{
			pf__utils_print(pf, pf->format, 1);
			pf->format++;
		}
	}
}
