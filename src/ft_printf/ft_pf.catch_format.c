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
#include <ft_io.h>

static int			catch_padding(
	char **format_s, t_pf_format *format)
{
	if (**format_s != '0' && ft_isdigit(**format_s))
	{
		format->padding = ft_atoi(*format_s);
		while (*format_s && ft_isdigit(**format_s))
		{
			(*format_s)++;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

static int			catch_format(
	char **format_s, char *str_option, t_pf_format *format)
{
	int ret;

	if ((ret = ft_strchr(str_option, **format_s)) != -1)
	{
		*(int *)format |= (1 << ret);
		(*format_s)++;
		return (0);
	}
	return (1);
}

static int			catch(
	char **format_s, char *str_option, t_pf_format *format, int unique)
{
	char *start;

	start = *format_s;
	while (**format_s)
	{
		if (catch_padding(format_s, format))
			continue ;
		else if (catch_format(format_s, str_option, format))
			break ;
		if (unique)
			break ;
	}
	return (start != *format_s ? 0 : 1);
}

int					pf__catch_format(t_pf *pf)
{
	pf->format++;
	if (*pf->format == '%')
	{
		ft_buffer_add(&pf->buff, "%", 1);
		pf->format++;
		return (1);
	}
	catch(&pf->format, "-*.0", &pf->format_bit, 0);
	catch(&pf->format, "....hl", &pf->format_bit, 0);
	if (OK != catch(&pf->format, "......sdcxbu", &pf->format_bit, 1))
		return (-1);
	return (0);
}
