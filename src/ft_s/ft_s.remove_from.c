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
#include "libft.h"

static int			check(t_s *s, size_t start)
{
	if (NULL == s)
	{
		return (ftlog__message(F, L,
				"fts__remove_from error: s ptr (null)",
				EINVAL));
	}
	else if (start >= s->length)
	{
		return (ftlog__message(F, L,
				"fts__remove_from error: start > length",
				EINVAL));
	}
	else
		return (0);
}

void	fts__remove_from(t_s *s, size_t start)
{
	if (check(s, start))
		return ;
	ft_bzero(s->data + start, s->length - start);
	s->length -= (s->length - start);
}
