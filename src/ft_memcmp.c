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

int ft_memcmp(void *mem1, void *mem2, size_t size)
{
	size_t i;
	unsigned char *s1;
	unsigned char *s2;

	s1 = mem1;
	s2 = mem2;
	i = 0;
	while (i < size)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		i++;
	}
	return (0);
}
