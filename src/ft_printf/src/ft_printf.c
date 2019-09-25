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

static void			handle_wildcard(t_pf *pf)
{
	if (pf->format_bit.wildard)
		pf->format_bit.padding = va_arg(pf->list, int);
}

static void			handle_variable(t_pf *pf)
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

static void			loop(t_pf *pf)
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

int					ft_printf(const char *format, ...)
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

int					ft_dprintf(int fd, const char *format, ...)
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

int					ft_sprintf(char *buffer, const char *format, ...)
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
