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

int ft_strcmp(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i]
		   && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_strncmp(char *s1, char *s2, int length)
{
	int i;

	i = 0;
	while (s1[i] == s2[i]
		   && s1[i] && s2[i]
		   && i < length)
		i++;
	if (length == i)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
