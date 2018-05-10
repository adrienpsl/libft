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

void	set_lenght_unsigned(t_pf *pf)
{
	if (pf->op.length == 'H')
		pf->data = (unsigned char)pf->data;
	else if (pf->op.length == 'h')
		pf->data = (unsigned short)pf->data;
	else if (pf->op.length == 'l')
		pf->data = (unsigned long)pf->data;
	else if (pf->op.length == 'j')
		pf->data = (uintmax_t)(pf->data);
	else if (pf->op.length == 'z')
		pf->data = (size_t)pf->data;
	else if (pf->op.length == 'L')
		pf->data = (unsigned long long)pf->data;
	else
		pf->data = (unsigned int)pf->data;
}

void	convert_base_fill_unsigned(t_pf *pf, char *base)
{
	int length_b;
	int i;

	i = 0;
	if (pf->data == 0)
		pf->pf_int.nb_s[0] = '0';
	length_b = ft_strlen(base);
	while (pf->data)
	{
		pf->pf_int.nb_s[i] = base[pf->data % length_b];
		pf->data /= length_b;
		i++;
	}
	ft_str_rev(pf->pf_int.nb_s);
}
