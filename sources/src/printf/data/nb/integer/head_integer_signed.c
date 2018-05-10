/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_into_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:49 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

static void		set_lenght_decimal(t_pf *pf)
{
	if (pf->op.length == 'H')
		pf->data = (char)pf->data;
	else if (pf->op.length == 'h')
		pf->data = (short)pf->data;
	else if (pf->op.length == 'l')
		;
	else if (pf->op.length == 'j')
		pf->data = (intmax_t)(pf->data);
	else if (pf->op.length == 'z')
		pf->data = (size_t)pf->data;
	else if (pf->op.length == 'L')
		pf->data = (long long)pf->data;
	else
		pf->data = (int)pf->data;
}

static void		fill_number_str_signed(long nb, t_pf *pf)
{
	int i;

	i = 0;
	if (nb == 0)
		pf->pf_int.nb_s[i] = '0';
	if (nb == LONG_MIN)
	{
		pf->pf_int.nb_s[i] = (LONG_MIN % 10) * -1 + '0';
		nb /= 10;
		i++;
	}
	if (nb < 0)
	{
		nb *= -1;
		pf->pf_int.neg = 1;
	}
	while (nb)
	{
		pf->pf_int.nb_s[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	ft_str_rev(pf->pf_int.nb_s);
}

void			manage_decimal(t_pf *pf)
{
	ft_memset(&pf->pf_int, 0, sizeof(t_int));
	if (pf->specifier == 'D')
		pf->op.length = 'l';
	set_lenght_decimal(pf);
	fill_number_str_signed(pf->data, pf);
	if (pf->data == 0 && pf->op.dot && !pf->op.nb_dot)
	{
		pf->pf_int.nb_s[0] = 0;
	}
	manage_before_printer(pf);
	manage_printer(pf);
}
