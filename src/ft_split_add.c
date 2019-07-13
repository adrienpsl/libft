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

char **ft_str_split_copy(char **split, int free)
{
	char **new;
	int i;

	if (!(new = ft_memalloc(sizeof(char *) * (ft_str_split_count(split) + 2))))
		return (NULL);
	i = 0;
	while (split[i])
	{
		if (!(new[i] = ft_strdup(split[i])))
			return (NULL);
		i++;
	}
	if (free)
		ft_str_split_free(&split);
	return (new);
}

char **ft_str_split_add(char **split, char *s, int free)
{
	int i;

	if (!(s = ft_strdup(s)))
		return (NULL);
	i = ft_str_split_count(split);
	split[i] = s;
	return (ft_str_split_copy(split, free));
}

char **ft_str_split_remove(char **split, char *s)
{
	int i;

	i = 0;
	while (split[i] != NULL)
	{
		if (ft_streq(split[i], s))
		{
			free(split[i]);
			while (split[i] != NULL)
			{
				split[i] = split[i + 1];
				i++;
			}
			return (split);
		}
		i++;
	}
	return (NULL);
}

char **ft_split_mix(char **split_1, char **split_2, int do_free)
{
	int i;
	int y;
	char **out;

	if (!(out =
		   ft_memalloc(sizeof(char **) * (ft_str_split_count(split_1) +
									 ft_str_split_count(split_2) + 2))))
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


