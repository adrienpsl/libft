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

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	char		*dest;
	const char	*src;

	dest = d;
	src = s;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		src = src + n - 1;
		dest = dest + n - 1;
		while (n > 0)
		{
			*dest-- = *src--;
			n--;
		}
	}
	else
	{
		while (n--)
			*dest++ = *src++;
	}
	return (d);
}
