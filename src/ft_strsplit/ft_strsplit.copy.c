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

char **ft_strsplit_copy(char **split, int free)
{
	char **new;
	int i;

	if (!(new = ft_memalloc(sizeof(char *) * (ft_strsplit_count(split) + 2))))
		return (NULL);
	i = 0;
	while (split[i])
	{
		if (!(new[i] = ft_strdup(split[i])))
			return (NULL);
		i++;
	}
	if (free)
		ft_strsplit_free(&split);
	return (new);
}

