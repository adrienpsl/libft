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

int		manage_neg_star(int nb, t_pf *pf)
{
	(void)pf;
	if (nb < 0)
	{
		nb = -nb;
		pf->op.left = 1;
	}
	return (nb);
}
long	get_star_nxt_argv(t_pf *pf)
{
	return (manage_neg_star(va_arg(*pf->ap, int), pf));
}

long	get_star_nxt_argv2(t_pf *pf)
{
	return (va_arg(*pf->ap, int));
}
