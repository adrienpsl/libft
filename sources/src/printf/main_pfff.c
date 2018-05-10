/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pfff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 17:00:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

static void			fucking_norme(t_pf *pf)
{
	if (check_char_into_str("Ddi", pf->specifier))
		manage_decimal(pf);
	else if (check_char_into_str("Uu", pf->specifier))
		manage_unsigned(pf);
	else if (check_char_into_str("Oo", pf->specifier))
		manage_octal(pf);
	else if (check_char_into_str("Xx", pf->specifier))
		manage_hexa(pf);
	else if (check_char_into_str("Bb", pf->specifier))
		manage_binaire(pf);
}

void				send_to_good_manager(t_pf *pf)
{
	if (check_char_into_str("DdiUuOXxoBb", pf->specifier))
		return (fucking_norme(pf));
	if (check_char_into_str("c", pf->specifier))
		return (manage_char(pf));
	else if (check_char_into_str("C", pf->specifier))
		return (manage_char2(pf));
	else if (check_char_into_str("s", pf->specifier))
		return (manage_str(pf));
	else if (check_char_into_str("S", pf->specifier))
		return (manage_str_big(pf));
	else if (check_char_into_str("Pp", pf->specifier))
		return (manage_ptr(pf));
	else if (check_char_into_str("%", pf->specifier))
		return (manage_percent(pf));
	else if (check_char_into_str("n", pf->specifier))
		return (manage_n(pf));
	else if (check_char_into_str("f", pf->specifier))
		return (manage_float(pf));
	else
		return (manage_fuck(pf));
}

long				ft_printf(char *str, ...)
{
	va_list	ap;
	t_pf	pf;

	set_null_pf(&pf);
	va_start(ap, str);
	pf.ap = &ap;
	pf.s = &str;
	ft_set_buff(&pf.buff);
	while (ft_printf_parseur(&pf))
	{
		pf.data = 0;
		if (pf.specifier == 'f')
			pf.data = va_arg(ap, double);
		else if (check_char_into_str("DdiOoUuxXcCsSpPBbnNf", pf.specifier))
			pf.data = va_arg(ap, long);
		send_to_good_manager(&pf);
	}
	va_end(ap);
	ft_print_buff(&pf.buff);
	return (pf.retour);
}
