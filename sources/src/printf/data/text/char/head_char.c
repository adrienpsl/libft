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

void	manage_char(t_pf *pf)
{
	if (pf->op.length == 'l' || pf->op.length == 'L')
		return manage_CHAR(pf);
	ft_memset(&pf->pf_int, 0, sizeof(t_int));
	pf->data = (unsigned char)pf->data;
	if (pf->data)
		pf->pf_int.nb_s[0] = pf->data;
	else
	{
		pf->op.putain_de_char = 1;
		pf->pf_int.nb_s[0] = 'a';
	}
	pf->op.nb_dot = 0;
	pf->op.dot = 0;
	manage_before_printer(pf);
	manage_printer(pf);
}

void	manage_CHAR(t_pf *pf)
{
	ft_memset(&pf->pf_int, 0, sizeof(t_int));
	if (pf->data)
		put_uni_into_tab(pf->data, pf->pf_int.nb_s, 4);
	else
	{
		pf->op.putain_de_char = 1;
		pf->pf_int.nb_s[0] = 'a';
		pf->specifier = 'c';
	}
	pf->op.nb_dot = 0;
	pf->op.dot = 0;
	manage_before_printer(pf);
	manage_printer(pf);
}
