/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_l_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:49:13 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../ft_library_header.h"

void		destroy_sll_l(t_sll_l *sll_l)
{
	t_sll_l link;

	link = *sll_l;
	if (link->content)
	{
		free(link->content);
		link->content = NULL;
	}
	link->next = NULL;
	free(link);
}

t_sll_l		new_sll_l(void *content, size_t size)
{
	t_sll_l link;

	if (content == NULL || size == 0)
		return (NULL);
	link = (t_sll_l)ft_malloc_protect(sizeof(t_sll_l_00));
	link->content = ft_malloc_protect(size);
	ft_memcpy(link->content, content, size);
	link->content_size = size;
	link->next = NULL;
	return (link);
}
