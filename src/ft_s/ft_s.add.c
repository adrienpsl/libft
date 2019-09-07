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

static int check(t_s *s, char *string)
{
	if (NULL == s)
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

int increase(t_s *s, size_t size)
{
	char *new_buffer;

	if (
		NULL == (new_buffer = ft_memalloc((size + s->capacity) + 2))
		)
		return (1);
	ft_memcpy(new_buffer, s->data, s->length);
	ftstr__free(&s->data);
	s->data = new_buffer;
	s->capacity += size;
	return (0);
}

int fts__add(t_s *s, char *str)
{
	size_t length;

	if (
		check(s, str)
		)
		return (-1);
	length = ft_strlen(str);
	if (s->length + length > s->capacity)
	{
		if (
			increase(s, length)
			)
			return (-1);
	}
	{
		ft_memcpy(s->data + s->length, str, length);
		s->length += length;
		return (0);
	}
}
