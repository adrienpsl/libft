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

#include <unistd.h>
#include "ft_mem.h"
#include "ft_str.h"

char *ft_strdup(const char *s)
{
	if (!s)
	    return (NULL);
	return (ft_memdup(s, ft_strlen(s) + 1));
}

char *ft_strndup(const char *s, size_t size)
{
	char *out;

	if (!s)
		return (NULL);
	out = ft_memdup(s, size + 1);
	out[size] = 0;
	return (out);
}