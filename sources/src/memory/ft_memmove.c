/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!len)
		return (dst);
	else if (!src && !dst)
		return (NULL);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (s < d)
	{
		s += len;
		d += len;
		while (len--)
			*--d = *--s;
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
