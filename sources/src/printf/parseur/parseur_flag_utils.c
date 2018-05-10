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

int	get_color(t_pf *pf)
{
	(*pf->s)++;
	pf->op.color = **pf->s;
	(*pf->s)++;
	return (1);
}

int	get_maj(t_pf *pf)
{
	(*pf->s)++;
	pf->op.police = **pf->s;
	(*pf->s)++;
	return (1);
}
