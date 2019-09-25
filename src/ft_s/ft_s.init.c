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
#include <ft_mem.h>

t_s *fts__init(size_t size)
{
	t_s		*s;
	char	*buffer;
	size_t	capacity;

	size = size == 0 ? 1 : size;
	capacity = (size * 2);
	if (NULL == (s = ft_memalloc(sizeof(t_s)))
		|| NULL == (buffer = ft_memalloc(capacity + 2)))
		return (NULL);
	s->data = buffer;
	s->capacity = capacity;
	return (s);
}

t_s *fts__init_data(char *str)
{
	t_s *s;

	if(NULL == (s = fts__init(0)))
		return (NULL);
	fts__add(s, str);
	return (s);
}
