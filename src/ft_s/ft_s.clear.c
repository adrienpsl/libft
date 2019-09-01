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
#include <errno.h>
#include <ft_log.h>
#include <ft_mem.h>

int fts__clear(t_s *s)
{
	if (NULL == s)
	{
		return (
			ftlog__message(F, L,
						   "ft_s$clear error: s ptr (null)",
						   EINVAL)
		);
	}
	else
	{
		ft_bzero(s->data, s->capacity);
		s->i = 0;
		return (0);
	}
}
