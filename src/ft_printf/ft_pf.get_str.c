/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int pf$get_str(t_pf *pf)
{
	if (
		pf->format_bit.string
		)
	{
		pf->intern_str = va_arg(pf->list, char*);
		return (1);
	}
	else if (
		pf->format_bit.character
		)
	{
		pf->char_buffer[0] = (char)va_arg(pf->list, int);
		pf->intern_str = pf->char_buffer;
		return (1);
	}
	else
		return (0);
}

