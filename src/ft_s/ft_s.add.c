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
			ft_log$message(F, L,
						   "ft_s$add error: s ptr (null)",
						   EINVAL)
		);
	}
	if (NULL == string)
	{
		return (
			ft_log$message(F, L,
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
		!(new = ft_s$init(s->capacity + size))
		)
	{
		return (NULL);
	}
	{
		ft_memcpy(new->data, s->data, s->i);
		new->i = s->i;
	}
	{
		ft_s$free(&s);
		return (new);
	}
}

int ft_s$add(t_s *s, char *str)
{
	size_t lenght;

	if (
		check(s, str)
		)
	{
		return (-1);
	}
	lenght = ft_strlen(str);
	if (s->i + lenght > s->capacity)
	{
		if (
			!(s = increase(s, lenght))
			)
			return (-1);
	}
	{
		ft_memcpy(s->data + s->i, str, lenght);
		return (0);
	}
}
