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

char	*ftstr__join_chr(char *str, char c, int do_free)
{
	char *new;
	int length;

	length = ft_strlen(str);
	if (NULL == (new = ft_memalloc(length + 2)))
		return (NULL);
	ft_strcat(new, str);
	new[length] = c;
	if (do_free)
		ftstr__free(&str);
	return (new);
}
