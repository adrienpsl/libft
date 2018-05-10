/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:49 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	if (!s2[0])
		return ((char*)s1);
	if (!len)
		return (0);
	while (s1[i] && len)
	{
		while (s1[i + y] == s2[y] && s2[y] && (len - y) > 0)
			y++;
		if (!s2[y])
			return ((char*)s1 + i);
		y = 0;
		i++;
		len--;
	}
	return (0);
}
