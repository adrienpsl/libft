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

char **ft_strsplit_mix(char **split_1, char **split_2, int do_free)
{
	int i;
	int y;
	char **out;

	if (!(out =
		   ft_memalloc(sizeof(char **) * (ft_strsplit_count(split_1) +
										  ft_strsplit_count(split_2) + 2))))
		return (NULL);
	i = -1;
	while (split_1[++i])
		out[i] = split_1[i];
	y = -1;
	i--;
	while (split_2[++y])
		out[++i + y] = split_2[y];
	if (do_free & FREE_FIRST)
		free(split_1);
	if (do_free & FREE_SECOND)
		free(split_2);
	return (out);
}

