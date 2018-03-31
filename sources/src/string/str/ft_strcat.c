/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:03 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char *ft_strcat(char *dest, const char *src)
{
	char *d;

	if (src == NULL)
		return (dest);
	d = dest;
	while (*d)
	{
		d++;
	}
	while (*src)
	{
		*d++ = *src++;
	}
	*d = 0;
	return (dest);
}

char *ft_charcat(char *dest, const char src)
{
	char *d;

	d = dest;
	while (*d)
	{
		d++;
	}
	*d++ = src;
	*d = 0;
	return (dest);
}