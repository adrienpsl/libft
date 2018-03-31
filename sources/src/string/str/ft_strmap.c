/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:11 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	size_t	i;

	if (!f)
		return (NULL);
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(out = ft_strnew(i)))
		return (NULL);
	while (*s)
	{
		*out++ = f(*s++);
	}
	*out = 0;
	return (out - i);
}
