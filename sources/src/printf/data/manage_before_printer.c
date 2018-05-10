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

static void		manage_first_char(t_pf *pf)
{
	if (check_char_into_str("UuCcSs", pf->specifier))
	{
		pf->pf_int.first_char[0] = 0;
		return ;
	}
	if (pf->pf_int.neg)
		pf->pf_int.first_char[0] = '-';
	else if (pf->op.plus)
		pf->pf_int.first_char[0] = '+';
	else if (pf->op.space)
		pf->pf_int.first_char[0] = ' ';
	else if (pf->op.diez)
	{
		if (check_char_into_str("Oo", pf->specifier))
			pf->pf_int.first_char[0] = '0';
		if (pf->specifier == 'X')
			ft_strcat(pf->pf_int.first_char, "0X");
		else if (check_char_into_str("xpP", pf->specifier))
			ft_strcat(pf->pf_int.first_char, "0x");
	}
}

static void		manage_precision(t_pf *pf, int size)
{
	pf->op.nb_dot -= size;
	if (pf->op.nb_dot < 0)
		pf->op.nb_dot = 0;
}

static void		manage_length(t_pf *pf, int size)
{
	if (pf->pf_int.first_char[0])
		pf->op.nb_space -= ft_strlen(pf->pf_int.first_char);
	if (pf->op.dot)
		if (pf->specifier == 's')
		{
			if (pf->text.precision < size)
				pf->op.nb_space -= pf->text.precision;
			else
				pf->op.nb_space -= size;
		}
		else if (pf->specifier == 'S')
		{
			if (pf->text.precision < size)
				pf->op.nb_space -= pf->text.precision;
			else
				pf->op.nb_space -= size;
		}
		else if (pf->op.nb_space < pf->op.nb_dot + size)
			pf->op.nb_space = 0;
		else
			pf->op.nb_space -= pf->op.nb_dot + size;
	else
		pf->op.nb_space -= size;
}

long			get_size(t_pf *pf)
{
	long size;

	if (check_char_into_str("S", pf->specifier))
	{
		size = strlen_uni(pf->text.u_out, pf->text.precision);
		return (size);
	}
	else if (check_char_into_str("s", pf->specifier))
	{
		size = ft_strlen(pf->text.out);
		if (pf->text.precision)
			return (pf->text.precision < size ? pf->text.precision : size);
		else
			return (size);
	}
	else
		return (ft_strlen(pf->pf_int.nb_s));
}

void			manage_before_printer(t_pf *pf)
{
	long size_nb;

	check_if_null_data(pf);
	if ((pf->op.dot || pf->op.left)
		&& check_char_into_str("DdiOoUuxXcCSpPBbnNf", pf->specifier))
		pf->op.zero = 0;
	size_nb = get_size(pf);
	manage_first_char(pf);
	manage_precision(pf, size_nb);
	manage_length(pf, size_nb);
}
