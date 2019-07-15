/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_streq(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && (s1[i] == s2[i]))
			i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		return (0);
	}
	return (0);
}

int ft_strneq(char const *s1, char const *s2, size_t size)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && size)
	{
		i++;
		size--;
	}
	return (size == 0 ? 1 : 0);
}
