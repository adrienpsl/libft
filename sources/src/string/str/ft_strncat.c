/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:12 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*s;

	s = dest;
	if (!n)
		return (s);
	while (*s)
		s++;
	while (*src && n)
	{
		*s++ = *src++;
		n--;
	}
	*s = 0;
	return (dest);
}
