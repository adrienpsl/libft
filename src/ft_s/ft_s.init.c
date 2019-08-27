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
	t_s *s;
	size_t capacity;

	size = size == 0 ? 1 : size;
	capacity = (size * 2);
	if (
		!(s = ft_memalloc(sizeof(t_s) + capacity + 2))
		);
	s->data = (char *)s + sizeof(t_s);
	s->capacity = capacity;
	return (s);
}
