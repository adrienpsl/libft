/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char		*ft_strdup(const char *s)
{
	int		i;
	char	*out;

	i = 0;
	if (!(out = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
