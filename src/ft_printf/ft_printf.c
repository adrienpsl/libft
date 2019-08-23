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

#include <ft_mem.h>
#include <ft_buffer.h>
# include "ft_printf.h"

static void handle_variable(t_pf *pf)
{
	if (
		OK == pf$catch_format(pf)
		)
	{
		pf$get_str(pf);
		pf$get_number(pf);
		pf$print(pf);
	}
	ft_bzero(&pf->format_bit, sizeof(t_pf_format));
	ft_bzero(&pf->char_buffer, 70);
}

static void loop(t_pf *pf)
{
	while (*pf->format)
	{
		if (
			*pf->format == '%'
			)
			handle_variable(pf);
		else
		{
			ft_buffer_add(&pf->buff, pf->format, 1);
			pf->format++;
		}
	}
}

int ft_printf(const char *format, ...)
{
	t_pf pf;

	ft_bzero(&pf, sizeof(t_pf));
	pf.buff.fd = 1;
	pf.format = (char *)format;
	{
		va_start(pf.list, format);
		loop(&pf);
		va_end(pf.list);
	}
	ft_buffer_clean(&pf.buff);
	return (0);
}

int ft_dprintf(int fd, const char *format, ...)
{
	t_pf pf;

	ft_bzero(&pf, sizeof(t_pf));
	pf.buff.fd = fd;
	pf.format = (char *)format;
	{
		va_start(pf.list, format);
		loop(&pf);
		va_end(pf.list);
	}
	ft_buffer_clean(&pf.buff);
	return (0);
}

int ft_sprintf(char *buffer, const char *format, ...)
{
	t_pf pf;

	ft_bzero(&pf, sizeof(t_pf));
	pf.extern_buff = buffer;
	pf.format = (char *)format;
	{
		va_start(pf.list, format);
		loop(&pf);
		va_end(pf.list);
	}
	ft_buffer_clean(&pf.buff);
	return (0);
}