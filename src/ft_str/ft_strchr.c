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

ssize_t ft_strchr(char *str, char c)
{
	size_t i;

	if (!str)
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

int					ft_strnchr(char *str, char c)
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
	return i;
}

ssize_t ft_strchrstr(char *str, char *searched)
{
	size_t i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (ft_strchr(searched, str[i]) > -1)
			return (i);
		i++;
	}
	return (-1);
}
