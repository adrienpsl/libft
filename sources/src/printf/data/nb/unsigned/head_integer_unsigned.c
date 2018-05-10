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

static void		fill_number_str_unsigned(unsigned long nb, t_pf *pf)
{
	int i;

	i = 0;
	if (nb == 0)
		pf->pf_int.nb_s[0] = '0';
	while (nb)
	{
		pf->pf_int.nb_s[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	ft_str_rev(pf->pf_int.nb_s);
}

void			manage_unsigned(t_pf *pf)
{
	ft_memset(&pf->pf_int, 0, sizeof(t_int));
	if (pf->specifier == 'U')
		pf->op.length = 'l';
	set_lenght_unsigned(pf);
	if (pf->data == 0 && pf->op.dot && !pf->op.nb_dot)
		;
	else
		fill_number_str_unsigned(pf->data, pf);
	manage_before_printer(pf);
	manage_printer(pf);
}
