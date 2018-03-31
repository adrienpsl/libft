/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:49 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*str;
	size_t		i;

	str = (char*)s;
	i = ft_strlen(s);
	while (i && str[i] != (char)c)
		i--;
	if (str[i] == (char)c)
		return (str + i);
	return (0);
}
