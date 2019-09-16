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

void	fts__free(t_s **s)
{
	if (NULL == s || NULL == *s)
	{
		ftlog__message(F, L,
			"fts__free error: s ptr (null)",
			EINVAL);
		return ;
	}
	fts__clear(*s);
	free((*s)->data);
	ft_bzero(*s, sizeof(t_s));
	free(*s);
	*s = NULL;
}
