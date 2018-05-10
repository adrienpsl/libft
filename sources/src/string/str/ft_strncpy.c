/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:13 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *s;

	if ((!dest && !src) || !n)
		return (dest);
	s = dest;
	while (*src && n)
	{
		*s++ = *src++;
		n--;
	}
	while (n)
	{
		*s++ = 0;
		n--;
	}
	return (dest);
}
