/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:58 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		*((unsigned char*)dest + i) = *((unsigned char*)src + i);
		i++;
	}
	return (dest);
}
