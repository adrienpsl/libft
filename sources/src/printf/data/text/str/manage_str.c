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

void	manage_str(t_pf *pf)
{
	if (pf->op.length == 'l' || pf->op.length == 'L')
	{
		pf->specifier = 'S';
		return (manage_str_big(pf));
	}
	ft_memset(&pf->text, 0, sizeof(t_text));
	pf->text.out = (char *)pf->data;
	pf->text.precision = pf->op.nb_dot;
	pf->op.nb_dot = 0;
	manage_before_printer(pf);
	manage_printer(pf);
}

void	manage_str_big(t_pf *pf)
{
	ft_memset(&pf->text, 0, sizeof(t_text));
	pf->text.u_out = (wchar_t *)pf->data;
	pf->text.precision = pf->op.dot ? pf->op.nb_dot : 4;
	pf->op.nb_dot = 0;
	manage_before_printer(pf);
	manage_printer(pf);
}
