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

int is_format(t_pf *pf, int position)
{
	return (*(int *)&pf->format_bit & (1 << position));
}

int ft_pf_get_variable(t_pf *s)
{
	static char bases[4][17] =
		{ "01", "0123456789", "0123456789abcdef", "0123456789ABCDF" };
	uintmax_t nb;
	int base;

	if (is_format(s, DECIMAL))
	    ;
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
						s->string,
						s->format & FORMAT_U);
}

