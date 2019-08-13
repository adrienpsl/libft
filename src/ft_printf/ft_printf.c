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
#include <ft_io.h>
# include "ft_printf.h"

int catch_options(char **input, char *str_option, long *options, int one)
{
	char *s;
	int ret;

	s = *input;
	if (one)
	{
		if (*s && (ret = ft_strchr(str_option, *s)) > -1)
		{
			*options |= (1 << ret);
			s++;
		}
	}
	else
	{
		while (*s && (ret = ft_strchr(str_option, *s)) > -1)
		{
			*options |= (1 << ret);
			s++;
		}
	}
	*input = s;
	return (0);
}

int extract_format(t_pf *s)
{
	s->format &= 0;
	ft_memset(s->t_string, 0, FT_BUFFER_SIZE);
	catch_options(&s->str, ".......-*.0", &s->format, 0);
	catch_options(&s->str, "....hl", &s->format, 0);
	catch_options(&s->str, "sdcu.....x", &s->format, 1);
	return (0);
}

int manage_wildcard(t_pf *s)
{
	if (s->format & FORMAT_WILDCARD)
		s->min_length = va_arg(s->list, int);
	return (0);
}

int ft_printf_parse_number(t_pf *s)
{
	static char *bases[17] = { "01", "0123456789", "0123456789abcdef" };
	uintmax_t nb;
	int base;

	if (FORMAT_D & s->format && !(s->format & FORMAT_L))
		nb = va_arg(s->list, int);
	else if (FORMAT_D & s->format && (s->format & FORMAT_L))
		nb = va_arg(s->list, long long);
	else if (FORMAT_U & s->format && !(s->format & FORMAT_L))
		nb = va_arg(s->list, unsigned int);
	else if (s->format & (FORMAT_U | FORMAT_L | FORMAT_X))
		nb = va_arg(s->list, unsigned long long);
	else
		return (1);
	base = (s->format & FORMAT_10_BASE) ? 1 : 2;
	return ft_itoa_base(nb,
						bases[base],
						s->t_string,
						s->format & FORMAT_U);
}

int ft_printf_read_arg(t_pf *s)
{
	if (s->format & FORMAT_S)
		s->ptr = va_arg(s->list, void*);
	else
		return ft_printf_parse_number(s);
	return (0);
}

static void add_padding(t_pf *s)
{
	while (s->min_length)
	{
		if (s->format & FORMAT_0)
			ft_buffer_add(s->buff, "0", 1);
		else
			ft_buffer_add(s->buff, " ", 1);
		s->min_length--;
	}
}

int ft_printf_format_data(t_pf *s)
{
	size_t size;
	char *data;

	data = s->format & FORMAT_S ? s->ptr : s->t_string;
	size = ft_strlen(data);
	s->min_length = s->min_length - size;
	if (s->format & FORMAT_0)
	{
		ft_buffer_add(s->buff, "0x", 2);
		s->min_length -= 2;
	}
	s->min_length = s->min_length < 0 ? 0 : s->min_length;
	s->min_length = s->min_length < 0 ? 0 : s->min_length;
	if (!(FORMAT_MINUS & s->format) && s->min_length)
		add_padding(s);
	ft_buffer_add(s->buff, data, size);
	if ((FORMAT_MINUS & s->format) && s->min_length)
		add_padding(s);
	return (0);
}

//int ft_sprintf(t_buffer *buffer, char *format, ...)
//{
//	static t_pf s;
//
//	ft_memset(&s, 0, sizeof(t_pf));
//	s.str = format;
////	s.buff = buffer;
//	va_start(s.list, format);
//	while (*s.str)
//	{
//		if (*s.str == '%' && s.str++)
//		{
//			extract_format(&s);
//			manage_wildcard(&s);
//			ft_printf_read_arg(&s);
//			ft_printf_format_data(&s);
//		}
////		else
////			ft_buffer_add(s.buff, s.str, 1) || s.str++;
//	}
//	va_end(s.list);
//	return (0);
//}

int ft_printf(const char *format, ...)
{
	t_pf s;

	ft_memset(&s, 0, sizeof(t_pf));
	if (!(s.buff = ft_array$init(512, 1)))
		return (1);
	s.str = (char*)format;
	va_start(s.list, format);
	while (*s.str)
	{
		if (*s.str == '%' && s.str++)
		{
			extract_format(&s);
			manage_wildcard(&s);
			ft_printf_read_arg(&s);
			ft_printf_format_data(&s);
		}
		else
			ft_buffer_add(s.buff, s.str, 1) || s.str++;
	}
	va_end(s.list);
	ft_buffer_clean(s.buff);
	free(s.buff);
	return (0);
}