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

static char			*get_base(t_pf *pf)
{
	static char base[5][17] = { "01", "0123456789", "0123456789abcdef" ,
							 "0123456789ABCDEF"};

	if (pf->format_bit.binary)
		return (base[0]);
	else if (pf->format_bit.hexa)
		return (base[2]);
	else if (pf->format_bit.b_hexa)
	    return (base[3]);
	else
		return (base[1]);
}

static int			itoa_unsigned(
	char *dest, uintmax_t nb, const char *base_str)
{
	int			i;
	size_t		base;
	uintmax_t	tmp;

	base = (size_t)ft_strlen(base_str);
	i = 0;
	tmp = nb;
	while (tmp /= base)
		i++;
	while (i > -1)
	{
		dest[i] = base_str[nb % base];
		nb /= base;
		i--;
	}
	return (0);
}

static uintmax_t	get_va_unsigned(t_pf *pf)
{
	if (pf->format_bit.tall)
		return (va_arg(pf->list, unsigned long));
	else if (pf->format_bit.little)
		return ((unsigned short)va_arg(pf->list, unsigned int));
	else
		return (va_arg(pf->list, unsigned int));
}

static uintmax_t	get_va_signed(t_pf *pf)
{
	intmax_t nb;

	if (pf->format_bit.tall)
		nb = (long)va_arg(pf->list, long);
	else if (pf->format_bit.little)
		nb = (short)va_arg(pf->list, int);
	else
		nb = va_arg(pf->list, int);
	if (nb < 0)
	{
		pf->char_buffer[0] = '-';
		nb = -nb;
	}
	return (nb);
}

int					pf__get_number(t_pf *pf)
{
	uintmax_t nb;

	if (pf->format_bit.unsign
		|| pf->format_bit.binary
		|| pf->format_bit.hexa
		|| pf->format_bit.b_hexa)
		nb = get_va_unsigned(pf);
	else if (pf->format_bit.decimal)
		nb = get_va_signed(pf);
	else
		return (0);
	itoa_unsigned(
		pf->char_buffer + ft_strlen(pf->char_buffer),
		nb,
		get_base(pf));
	pf->intern_str = pf->char_buffer;
	return (1);
}
