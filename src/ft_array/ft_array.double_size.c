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

#include <ft_array.h>
#include <ft_errno.h>
#include <ft_mem.h>
#include <ft_log.h>

t_array *ft_array$double_size(t_array *src)
{
	t_array *new;

	if (NULL == src)
	{
		ft_log$message(F, L, "ft_array$double size error: array ptr (null)",
					   EINVAL);
		return (NULL);
	}
	if (
		!(new = ft_array$init(src->capacity, src->element_size))
		)
		return (NULL);
	ft_memcpy(new->data,
			  src->data,
			  (src->length * src->element_size));
	new->length = src->length;
	ft_array$free(&src);
	return (new);
}