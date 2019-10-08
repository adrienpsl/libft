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

#include <libft.h>

ssize_t		ft_strchr_int(char *str, char c)
{
	size_t i;

	if (!str || *str == '\0')
		return (-1);
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (c == *str)
			return (str);
		str += 1;
	}
	return (NULL);
}

int			ft_strnchr(char *str, char c)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

ssize_t		ft_strchrs(char *str, char *searched)
{
	size_t i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (ft_strchr_int(searched, str[i]) > -1)
			return (i);
		i++;
	}
	return (-1);
}
