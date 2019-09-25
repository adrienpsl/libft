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

char	*ft_strjoin(char *start, char *end, int free)
{
	size_t	length_start;
	size_t	length_end;
	char	*new;

	if (NULL == start || NULL == end)
		return (NULL);
	length_start = ft_strlen(start);
	length_end = ft_strlen(end);
	if (NULL != (new = ft_memalloc(length_start + length_end + 1)))
	{
		ft_strcat(new, start);
		ft_strcat(new, end);
		if (1 == free || free == 3)
			ftstr__free(&start);
		if (2 == free || free == 3)
			ftstr__free(&end);
	}
	return (new);
}
