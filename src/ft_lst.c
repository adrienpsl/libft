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

#include <libft.h>
# include "ft_list.struct.h"

t_list *ft_lstnew(const void *content, size_t content_size)
{
	t_list *link;

	if (NULL == content)
		return (NULL);
	if (NULL == (link = malloc(sizeof(t_list))))
		return (NULL);
	if (NULL == (link->content = malloc(content_size)))
		return (NULL);
	ft_memcpy(link->content, content, content_size);
	link->content_size = content_size;
	return (link);
}

void ft_lstaddend(t_list *lst, t_list *new)
{
	if (!lst || !new)
		return;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

void ft_lstdel(t_list *list, void (*del)(void *, size_t))
{
	if (list->next)
		ft_lstdel(list->next, del);
	del(list->content, list->content_size);
	free(list);
}
