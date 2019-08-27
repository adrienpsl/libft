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
#include <ft_str.h>
#include <ft_mem.h>

static int check(t_s **s, char *string)
{
	if (NULL == s || NULL == *s)
	{
		return (
			ftlog__message(F, L,
						   "ft_s$add error: s ptr (null)",
						   EINVAL)
		);
	}
	if (NULL == string)
	{
		return (
			ftlog__message(F, L,
						   "ft_s$add error: str ptr (null)",
						   EINVAL)
		);
	}
	return (0);
}

t_s *increase(t_s *s, size_t size)
{
	t_s *new;

	if (
		!(new = fts__init(s->capacity + size))
		)
	{
		return (NULL);
	}
	{
		ft_memcpy(new->data, s->data, s->i);
		new->i = s->i;
	}
	{
		fts__free(&s);
		return (new);
	}
}

int fts__add(t_s **p_s, char *str)
{
	size_t length;
	t_s *s;

	if (
		check(p_s, str)
		)
	{
		return (-1);
	}
	{
		s = *p_s;
		length = ft_strlen(str);
	}
	if (s->i + length > s->capacity)
	{
		if (
			!(s = increase(s, length))
			)
			return (-1);
	}
	{
		ft_memcpy(s->data + s->i, str, length);
		*p_s = s;
		return (0);
	}
}
