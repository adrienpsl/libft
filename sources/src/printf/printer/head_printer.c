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

#include "../../../ft_library_header.h"

void		putaindechar(t_pf *pf)
{
	pf->pf_int.nb_s[0] = 0;
	ft_print_buff(&pf->buff);
	write(1, &pf->data, 1);
	pf->retour++;
	pf->op.putain_de_char = 0;
}

void		put_first_in_buf(t_pf *pf)
{
	buff_set_or_print(pf->pf_int.first_char, pf);
	pf->pf_int.first_char[0] = 0;
}

void		print_by_left(t_pf *pf)
{
	buff_set_or_print(pf->pf_int.first_char, pf);
	printer_precision(pf);
	if (pf->op.putain_de_char)
		putaindechar(pf);
	printer_value(pf);
	printer_space(pf);
}

void		print_by_right(t_pf *pf)
{
	if (pf->op.nb_space == 0 && pf->pf_int.first_char[0])
		put_first_in_buf(pf);
	if (pf->op.zero && pf->pf_int.first_char[0])
		put_first_in_buf(pf);
	printer_space(pf);
	if (pf->pf_int.first_char[0])
		buff_set_or_print(pf->pf_int.first_char, pf);
	printer_precision(pf);
	if (pf->op.putain_de_char)
		putaindechar(pf);
	printer_value(pf);
}

void		manage_printer(t_pf *pf)
{
	put_color(pf);
	if (pf->op.left)
		print_by_left(pf);
	else
		print_by_right(pf);
	if (pf->op.color != 0)
		buff_set_or_print("\033[0m", pf);
}
