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

#include <ft_printf.h>
#include <ft_str.h>
#include <ft_mem.h>

void	pf__utils_print(t_pf *pf, char *data, int size)
{
	if (pf->extern_buff)
		ft_memcpy(pf->extern_buff + ft_strlen(pf->extern_buff), data, size);
	else
	{
		ft_buffer_add(&pf->buff, data, size);
	}
}
