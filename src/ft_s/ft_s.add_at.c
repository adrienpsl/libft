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

static int			check(t_s *s, char *string, size_t index)
{
	if (NULL == s)
	{
		return (ftlog__message(F, L,
			"fts__add_at error: s ptr (null)",
			EINVAL));
	}
	if (NULL == string)
	{
		return (ftlog__message(F, L,
			"fts__add_at error: str ptr (null)",
			EINVAL));
	}
	if (index > s->length)
	{
		return (ftlog__message(F, L,
			"fts__add_at error: index bigger than length", EINVAL));
	}
	return (0);
}

int					fts__add_at(t_s *s, char *str, size_t index)
{
	t_s *s_tmp;

	if (OK != check(s, str, index))
		return (-1);
	if (NULL == (s_tmp = fts__init(s->length + ft_strlen(str))))
		return (-1);
	fts__addn(s_tmp, s->data, index);
	fts__add(s_tmp, str);
	fts__add(s_tmp, s->data + index);
	free(s->data);
	ft_memcpy(s, s_tmp, sizeof(t_s));
	free(s_tmp);
	return (OK);
}
