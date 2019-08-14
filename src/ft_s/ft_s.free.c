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

#include <ft_s.h>
#include <ft_log.h>
#include <ft_mem.h>

void ft_s$free(t_s **s)
{
	if (NULL == s || NULL == *s)
	{
		ft_log$message(F, L,
					   "ft_s$free error: s ptr (null)",
					   EINVAL);
		return;
	}
	ft_bzero(*s, sizeof(t_s) + (*s)->i);
	*s = NULL;
}
