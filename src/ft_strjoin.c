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
#include "ft_strjoin.h"

char *ft_strjoin(const char *s1, const char *s2)
{
	char *dest;
	size_t size_1;
	size_t size_2;

	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	if (!(dest = ft_strnew(size_1 + size_2)))
		return (NULL);
	ft_memcpy(dest, s1, size_1);
	ft_memcpy(dest + size_1, s2, size_2);
	return (dest);
}

int ft_strjoin_buffer(char **dest, const char *s1, const char *s2)
{
	size_t size_1;
	size_t size_2;

	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	ft_memcpy(*dest, s1, size_1);
	ft_memcpy(*dest + size_1, s2, size_2);
	return (0);
}

char *ft_strjoinby(const char *start, char *middle, char *end)
{
	size_t length[3];
	char *dest;
	char *current;

	length[START] = ft_strlen(start);
	length[MIDDLE] = ft_strlen(middle);
	length[END] = ft_strlen(end);
	if (!(dest = ft_strnew(length[START] + length[MIDDLE] + length[END])))
		return (NULL);
	current = dest;
	ft_memcpy(current, start, length[START]);
	current += length[START];
	ft_memcpy(current, middle, length[MIDDLE]);
	current += length[MIDDLE];
	ft_memcpy(current, end, length[END]);
	return (dest);
}

int ft_strjoinbybuffer(char **dest, const char *start, char *middle, char *end)
{
	size_t size_start;
	size_t size_end;
	size_t size_middle;
	char *current;

	size_start = ft_strlen(start);
	size_middle = ft_strlen(middle);
	size_end = ft_strlen(end);
	current = *dest;
	ft_memcpy(current, start, size_start);
	current += size_start;
	ft_memcpy(current, middle, size_middle);
	current += size_middle;
	ft_memcpy(current, end, size_end);
	return (0);
}