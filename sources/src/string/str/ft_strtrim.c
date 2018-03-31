/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:47 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char	*ft_strtrim(char const *s)
{
	size_t	size;
	char	*s2;

	if (!s)
		return (NULL);
	while (check_char_into_str(" \n\t", *s) && *s)
		s++;
	if (!*s)
		return (ft_strnew(1));
	s2 = (char*)s + (ft_strlen(s) - 1);
	size = ft_strlen(s);
	while (check_char_into_str(" \n\t", *s2))
	{
		s2--;
		size--;
	}
	return (ft_strndup(s, size));
}
