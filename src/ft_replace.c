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
#include "ft_replace.h"

int ft_str_search(char *str, char *searching)
{
	int i;
	int y;

	if (!str || !searching)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == searching[0])
		{
			y = 1;
			while (str[i + y] && searching[y]
				   && str[i + y] == searching[y])
				y++;
			if (searching[y] == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

char *ft_str_replace(char *str, char *searching, char *replacing)
{
	ssize_t match_i;
	size_t length[4];
	char *current;
	char *out;

	if (!str || !searching || !replacing)
		return (NULL);
	match_i = ft_str_search(str, searching);
	if (match_i > -1)
	{
		length[STR] = ft_strlen(str);
		length[SEARCHING] = ft_strlen(searching);
		length[REPLACING] = ft_strlen(replacing);
		length[OUT] = length[STR] - (length[SEARCHING] - length[REPLACING]);
		if (!(out = ft_strnew(length[OUT])))
			return (NULL);
		current = out;
		if (match_i)
			ft_memcpy(current, str, match_i);
		ft_memcpy((current += match_i), replacing, length[REPLACING]);
		ft_memcpy((current += length[REPLACING]),
					str + match_i + length[SEARCHING], STRING_MODE);
		return (0);
	}
	return (NULL);
}


