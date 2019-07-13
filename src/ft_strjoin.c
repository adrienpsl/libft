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

char *ft_strjoin(const char *s1, const char *s2, int do_free)
{
	char *dest;

	if (!(dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	return (ft_strjoinbuffer(dest, s1, s2, do_free));
}

char *ft_strjoinbuffer(char *dest, const char *s1, const char *s2, int do_free)
{
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	if (do_free & FREE_FIRST)
		free((void *) s1);
	if (do_free & FREE_SECOND)
		free((void *) s2);
	return (dest);
}

char *ft_strjoinby(char *start, char *middle, char *end, int do_free)
{
	char *dest;

	if (!(dest = ft_strnew(
	 ft_strlen(start) + ft_strlen(middle) + ft_strlen(end))))
		return (NULL);
	ft_strcat(dest, start);
	ft_strcat(dest, middle);
	ft_strcat(dest, end);
	if (do_free & FREE_FIRST)
	    free(start);
	if (do_free & FREE_SECOND)
	    free(middle);
	if (do_free & FREE_THIRD)
	    free(end);
	return (dest);
}

char *ft_strjoinbybuffer(char *dest, const char *start, char *middle, char *end)
{
	ft_strcat(dest, start);
	ft_strcat(dest, middle);
	ft_strcat(dest, end);
	return (dest);
}