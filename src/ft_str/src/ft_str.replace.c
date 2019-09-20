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

char *ftstr__replace_str(char *src, char *from, char *to)
{
	char *new;
	char *find;
	size_t start;
	size_t end;

	new = NULL;
	if (NULL == src || from == NULL || to == NULL)
		return (NULL);
	if (NULL != (find = ftstr__find_str(src, from)))
	{
		start = find - src;
		end = ft_strlen(find + ft_strlen(from));
		if (NULL ==
			(new = ft_memalloc(start + ft_strlen(from) + end + 1)))
			return (NULL);
		ft_memcpy(new, src, start);
		ft_strcat(new, to);
		ft_strcat(new, find + ft_strlen(from));
	}
	return (new);
}
