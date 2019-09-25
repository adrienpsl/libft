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

char	*ftstr__find_str(char *str, char *to_find)
{
	size_t	len;

	if (*to_find != '\0')
	{
		len = ft_strlen(to_find);
		while (ft_strncmp(str, to_find, len) != 0)
		{
			if (*str == '\0')
				return (NULL);
			str++;
		}
	}
	return ((char *)str);
}
