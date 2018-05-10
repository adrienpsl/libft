/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:14 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char		*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*out;

	if (!s1)
		return (NULL);
	if (!n)
		return (ft_strdup(s1));
	if (!(out = (char*)malloc(sizeof(ft_strlen(s1) + n + 1))))
		return (NULL);
	ft_strcpy(out, s1);
	ft_strncat(out, s2, n);
	return (out);
}
