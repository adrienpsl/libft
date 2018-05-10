/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 17:00:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

static void		set_null_uni(wchar_t *s, t_pf *pf)
{
	int i;

	i = 0;
	while (s[i])
	{
		pf->uni_nul[i] = s[i];
		i++;
	}
	pf->uni_nul[i] = 0;
}

void			set_null_pf(t_pf *pf)
{
	ft_memset(pf->null, 0, 8);
	ft_strcat(pf->null, "(null)");
	set_null_uni(L"(null)", pf);
	pf->retour = 0;
}

void			check_if_null_data(t_pf *pf)
{
	if (pf->data == 0)
	{
		if (check_char_into_str("s", pf->specifier))
			pf->text.out = &(pf->null[0]);
		else if (check_char_into_str("S", pf->specifier))
			pf->text.u_out = &(pf->uni_nul[0]);
	}
}
