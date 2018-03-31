/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:57 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (n)
	{
		if ((unsigned char)c == *str)
			return ((void*)(str));
		n--;
		str++;
	}
	return (NULL);
}
