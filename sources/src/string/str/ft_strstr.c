/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:48 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t y;

	y = 0;
	if (!s2[0])
		return ((char*)s1);
	while (*s1)
	{
		while (s1[y] == s2[y] && s2[y])
			y++;
		if (!s2[y])
			return ((char*)s1);
		y = 0;
		s1++;
	}
	return (NULL);
}
