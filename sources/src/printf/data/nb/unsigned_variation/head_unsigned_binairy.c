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

void	manage_binaire(t_pf *pf)
{
	ft_memset(&pf->pf_int, 0, sizeof(t_int));
	set_lenght_unsigned(pf);
	convert_base_fill_unsigned(pf, "01");
	pf->op.plus = 0;
	pf->op.space = 0;
	manage_before_printer(pf);
	manage_printer(pf);
}